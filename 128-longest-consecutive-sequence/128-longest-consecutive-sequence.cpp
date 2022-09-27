class Solution {
private:
int cnt=INT_MIN;
void subseq(vector<int>&arr,int idx,int n,vector<int>&nums){
    if(idx==n){
        map<int,int>mp;
        for(int i=1;i<=n;i++){
          mp[nums[i]-nums[i-1]]++;
        }
        if(mp.size()==1){
            cnt=max(cnt,mp[nums[1]-nums[0]]);
        }
        return;
    }
    nums.push_back(arr[idx]);
    subseq(arr,idx+1,n,nums);
    nums.pop_back();
    subseq(arr,idx+1,n,nums);
}
public:
    int longestConsecutive(vector<int>& nums) {
      //int cnt=0;
      int n=nums.size();
  if(nums.empty()){
          return 0;
      }
        if(nums.size()==1){
            return 1;
        }
        /*  vector<int>v;
      
     // subseq(nums,0,n,v);
        map<int,int>mp;
      for(int i=1;i<=n;i++){
          int dist=nums[i]-nums[i-1];
         if(dist>0)
           mp[dist]++;
      }
    for(auto it:mp){
        if(it.second>cnt){
            cnt=max(cnt,it.second);
        }
    }
        if(cnt==INT_MIN)
            return 1;
      return cnt+1;*/
     int d=0,c=0;
        sort(nums.begin(),nums.end());
    for(int i=1;i<n;i++){
        if(nums[i]-nums[i-1]==1){
            c++;
        }else if(nums[i]-nums[i-1]==0){
            continue;
        }else{
            d=max(d,c);
            c=0;
        }
    }
    return max(d,c)+1;
    }
};