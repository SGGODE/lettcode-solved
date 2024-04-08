class Solution {
public:
    int countStudents(vector<int>& students, vector<int>&sand) {
        map<int,int>mp,mx;
        queue<int>pq;
        for(auto&it:students){
            mp[it]++;
            pq.push(it);
        }
        for(auto&it:sand)mx[it]++;
        int j = 0;
        while(!pq.empty()){
            int node = pq.front();
            if(!mp.count(sand[j]))break;
            pq.pop();
            if(node==sand[j]){
                --mx[sand[j]];
                if(mx[sand[j]]==0)mx.erase(sand[j]);
                j++;
                --mp[node];
                if(mp[node]==0)mp.erase(node);
            }else{
                pq.push(node);
            }
        }
        return pq.size();
    }
};