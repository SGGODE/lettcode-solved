 class Solution {
 public:
//     int maxSubarraySumCircular(vector<int>& A) {
//         //sort(nums.begin(),nums.end());
//         //int n=nums.size();
//         // int msum=INT_MIN;
//         // vector<int>v(nums);
//         // for(int i=0;i<n;i++){
//         //     v.push_back(nums[i]);
//         // }
//         // for(int i=0;i<n+n;i++){
//         //   int sum=0; vector<bool>vis((2*n),0);
//         //   for(int j=i;j<n+n;j++){
//         //       if(vis[j])break;
//         //       sum+=v[j]; msum=max(msum,sum);
//         //       vis[j]=1;vis[j+n]=1;
//         //   }
//         // }
//         // vector<int>prefix;
//         // int sum=0;
//         // for(int i=0;i<n;i++){
//         //     sum+=nums[i];
//         //     prefix.push_back(sum);
//         // }
//         // for(auto &it:prefix)cout<<it<<" ";
//         // cout<<endl;
//         // for(int i=0;i<n;i++){
//         //       int sum=0;
//         //     for(int j=i;j<i+n;j++){
//         //       sum+=v[j];
//         //       msum=max(msum,sum);
//         //     }
//         // }
//         
     int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};
