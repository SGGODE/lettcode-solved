class Solution {
public:
    int maxProduct(vector<int>& nums) {
       priority_queue<int>pq(nums.begin(),nums.end());
       int num = pq.top()-1;
        pq.pop();
       return (pq.top()-1)*num;
    }
};