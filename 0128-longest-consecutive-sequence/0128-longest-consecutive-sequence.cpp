class Solution {
private:
    int sub(vector<int>&dp,vector<int>&nums,int index,int last){
        if(index==nums.size())return 0;
        int notpick=sub(dp,nums,index+1,last);
        int pick=0;
        if(last==1e9+7){
            pick=1+sub(dp,nums,index+1,nums[index]);
        }
        else if(last+1==nums[index]){
             pick=max(pick,1+sub(dp,nums,index+1,nums[index]));
        }
        return dp[index]=max(pick,notpick);
    }
public:
    int longestConsecutive(vector<int>& nums) {
     //    if(nums.empty())return 0;
     //    sort(nums.begin(),nums.end());
     //   for(auto&it:nums)cout<<it<<" ";
     //   cout<<endl;
     //   // int n = nums.size();
     // //   vector<int>dp(n,-1);
     // //   return sub(dp,nums,0,1e9+7);
     //    int len = 0;
     //    int cnt = 1;
     //    int last = nums[0];
     //    for(int i=1;i<nums.size();i++){
     //        if(abs(abs(nums[i])-abs(last))==1||(nums[i]==last)){
     //            if(abs(abs(nums[i])-abs(last))==1){
     //                ++cnt;
     //                last=nums[i];
     //            }
     //        }else{
     //            len=max(len,cnt);
     //            cnt=1;
     //            last=nums[i];
     //        }
     //    }
     //    len=max(len,cnt);
     //    return len;
         unordered_set<int>s(nums.begin(),nums.end());
        int cnt=1;
        int longest=INT_MIN;
        int last=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                int j=nums[i];
                cnt=1;
                while(s.find(j+1)!=s.end()){
                    ++j;
                    ++cnt;
                }
                longest=max(cnt,longest);
            }
        }
        if(longest==INT_MIN)return 0;
        return longest;
    }
};