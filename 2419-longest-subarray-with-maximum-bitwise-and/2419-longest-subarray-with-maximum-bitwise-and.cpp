class Solution {
/*private:
void help(vector<vector<int>>x,vector<int>v,vector<int>h,int idx,int n){
    if(idx==n){
       x.push_back(h);
       return;
    }
    h.push_back(v[idx]);
    help(x,v,h,idx+1,n);
    h.pop_back();
    help(x,v,h,idx+1,n);
}*/
public:
    int longestSubarray(vector<int>& nums) {
      /* // int mlen=INT_MIN;
        int band=INT_MIN;
        vector<vector<int>>v;
        vector<int>h;
       
        help(v,nums,h,0,n);
        int mans=0;
        int mlen=0;
        for(int i=0;i<v.size();i++){
            int cnt=1,nas=v[i][0];
            for(int j=1;j<v[i].size();j++){
                nas=nas and v[i][j];
                cnt++;
            }
            if(band<nas){
                band=nas;
                mlen=cnt;
            }
        }
        return mlen;
        int n=nums.size();
        vector<vector<int>>x;
        map<int,int>mp;
       for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
             vector<int>h;
              int nas;
               for(int k=i;k<=j;k++){
                  nas=nas and nums[k];
             }
             mp[nas]=j-i;
            x.push_back(h);
         }
       }
        int mlen=0;
        int mans=INT_MIN;
      for(auto it:mp){
         if(it.first>mans){
             mans=it.first;
             mlen=it.second;
         } 
      }
      return mlen;*/
      int m=*max_element(nums.begin(),nums.end());
      int ans=1,subarray=0;
     for(int i=0;i<nums.size();i++){
         if(nums[i]==m){
             subarray++;
             ans=max(ans,subarray); 
         }else{
             subarray=0;
         }
     }
    return ans;
    }
};