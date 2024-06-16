class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
       int n = skills.size();
       int wins = 0;
       queue<pair<int,int>>pq;
       for(int i=0;i<n;i++)pq.push({skills[i],i});
       int maxi = *max_element(skills.begin(),skills.end());
       int cwins = k;
       while(!pq.empty()){
           int node = pq.front().first;
           if(node==maxi)return pq.front().second;
           int index = pq.front().second;
           pq.pop();
           while(!pq.empty()&&pq.front().first<node&&cwins){
               pq.push({pq.front().first,pq.front().second});
               pq.pop();
               --cwins;
           }
           if(!cwins)return index;
           else{
               pq.push({node,index});
               cwins=k-1;
           }
       }
       return -1;
    }
};