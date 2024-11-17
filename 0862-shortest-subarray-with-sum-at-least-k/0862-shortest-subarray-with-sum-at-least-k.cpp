class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // unordered_map<int,int>sumNums;
        // sumNums[0] = 0;
        long long int sum = 0;
        int len = 1e9;
        priority_queue<pair<long long int,int>,
                       vector<pair<long long int,int>>,
                       greater<pair<long long int,int>>> pq;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum >= k)len = min(len , i+1);
            while(!pq.empty() && (sum - pq.top().first) >= k){
               // cout<<pq.top().first<<" "<<endl;
                len = min(len , (i - pq.top().second));
                pq.pop();
            }
         //   sumNums[sum] = i+1;
            pq.push({sum,i});
        }
     
        return len == 1e9 ? -1 : len;
    }
};