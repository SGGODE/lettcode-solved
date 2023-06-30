class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int mod=1e9+7;
       int cnt=INT_MIN;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++){
        //     if(i>=1){
        //         int j=i-1;int temp=k;
        //         while(j>=0&&temp!=0&&nums[i]-nums[j]<=temp){
        //             temp=temp -(nums[i]-nums[j]);
        //             --j;
        //         }
        //         cnt=max(cnt,(i-j));
        //     }
        // }
        int l=0;
        int r=0;
        long long int total=0;
        while(l<n&&r<n){
            total=(long long)total+nums[r];
            long long temp=(long long)nums[r]*((r-l)+1);
            if(temp<=total+k){
                cnt=max(cnt,(r-l)+1);
                 r++;
            }else{
                 long long temp=(long long)nums[r]*((r-l)+1);
               while(!(temp<=total+k)&&l<r){
                   total-=nums[l];
                   ++l;
                   temp=(long long)nums[r]*((r-l)+1);
               }
                r++;
            }
        }
        return cnt;
    }
};