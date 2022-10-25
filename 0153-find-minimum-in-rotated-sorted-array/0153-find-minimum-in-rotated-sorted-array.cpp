class Solution {
public:
    int findMin(vector<int>& nums) {
        //return *min_element(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        return pq.top();
    }
};