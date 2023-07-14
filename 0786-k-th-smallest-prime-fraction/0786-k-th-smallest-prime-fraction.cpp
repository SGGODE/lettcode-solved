class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>&nums, int k) {
        priority_queue<pair<double,pair<int,int>>>pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double num1=0,num2=0;
                num1+=nums[i];num2+=nums[j];
                double x = num1/num2;
                pq.push({x,{nums[i],nums[j]}});
                if(pq.size()>k)pq.pop();
            }
        }
        return {pq.top().second.first,pq.top().second.second};
    }
};