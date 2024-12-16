class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        //vector<pair<int,int>>store;
        //sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0; i < n; i++){
            pq.push({nums[i] , i});
        }
        while(k--){
            int value = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            pq.push({value*multiplier , index});
        }
        while(!pq.empty()){
            nums[pq.top().second] = pq.top().first;
            pq.pop();
        }
        return nums;
    }
};