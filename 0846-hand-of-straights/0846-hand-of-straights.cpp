class Solution {
public:
    bool isNStraightHand(vector<int>&nums, int k) {
        int n=nums.size();
        if(n%k!=0){
          //  cout<<'y'<<k<<endl;
            return 0;
        }
       // map<pair<int,int>>mp;
       // for(auto it:nums)mp[it]++;
        vector<bool>vis(n,0);
        sort(nums.begin(),nums.end());
      for(int i=0;i<n;i++){
       long long int curr=nums[i];long long int cnt=1;
         if(!vis[i]){
            for(int j=i+1;j<n;j++){
                if((curr+1)==nums[j]&&cnt<k&&!vis[j]){
                    vis[j]=1;
                    curr=nums[j];
                    ++cnt;
                }
            }
            if(cnt<k){
                cout<<cnt<<" "<<curr<<" "<<nums[i]<<endl;
                cout<<nums[i]<<endl;return 0;
            }
         }
       }
        return 1;
    }
};