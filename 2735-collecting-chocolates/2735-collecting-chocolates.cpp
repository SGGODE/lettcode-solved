class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n=nums.size();
        long long int sum=0;
        vector<long long int>res(n,0);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            res[i]=nums[i];
        }
        for(long long int i=1;i<n;i++){
            long long int rate=i*x;
            long long int cost=rate;
            for(long long int j=0;j<n;j++){
                long long int xi=nums[(j+i)%n];
                res[j]=min(res[j],xi);
                cost+=res[j];
            }
            sum=min(sum,cost);
        }
        return sum;
    }
};