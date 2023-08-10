class Solution {
private:
    int sub(vector<int>&dp,vector<int>&res,int index){
       if(index==res.size()-1)return 1e9;
       if(index>=res.size())return 0; 
       if(index+1<res.size()&&res[index]!=res[index+1])return 1e9;
       int ans=0;
       if(dp[index]!=-1)return dp[index];
       if(index+1<res.size()&&res[index]==res[index+1]){
              ans=1+sub(dp,res,index+2);
        }
       if(index+2<res.size()&&(res[index]==res[index+1])&&(res[index]==res[index+2])){
           ans=min(ans,1+sub(dp,res,index+3));
       }
      return dp[index]=ans;
}
public:
    int minimumRounds(vector<int>&res) {
      int n = res.size();
      if(n==1)return -1;
      vector<int>dp(n,-1);
      sort(res.begin(),res.end());
      int result = sub(dp,res,0);
      return result>=1e9?-1:result;
    }
};