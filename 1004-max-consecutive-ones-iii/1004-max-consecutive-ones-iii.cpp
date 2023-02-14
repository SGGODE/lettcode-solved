class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j=0;
        int i=0;
        int n=nums.size();
        int cnt=INT_MIN,zero=0;
        int x=0;
        for(auto it:nums)if(it==0)++x;
        if(x<=k)return n;
        for(i=0;i<n;i++){
            if(nums[i]==0)++zero;
            if(zero>k){
                cnt=max(cnt,i-j);
                //int cur_zero=0;
                while(!(zero==k)&&j<n&&j<=i){
                    if(nums[j]==0)--zero;
                    ++j;
                }
               // zero-=cur_zero;
            }else cnt=max(cnt,i-j);
        }
        cnt=max(cnt,(n-j));
        return cnt;
    }
};