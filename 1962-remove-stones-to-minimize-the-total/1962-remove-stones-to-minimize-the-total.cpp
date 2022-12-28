class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
       // sort(piles.begin(),piles.end());
        int n=piles.size();
        priority_queue<int>pq(piles.begin(),piles.end());
        int sum = accumulate(piles.begin(),piles.end(),0);
        while(k--){
            int x=pq.top()-(pq.top()/2);
           // cout<<x<<endl;
            sum-=x;
            pq.pop();
            pq.push(x);
        }
        // for(int i=n-1;i>=0&&k>0;i--){
        //     //piles[i]=piles[i]
        //     sum-=floor(piles[i]/2);
        //     --k;
        // }
        sum=0;
        while(!pq.empty()){
            //cout<<pq.top()<<" ";
            sum+=pq.top();
            pq.pop();
        }
        //cout<<endl;
        return sum;
    }
};