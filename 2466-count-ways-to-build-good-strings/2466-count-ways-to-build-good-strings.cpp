class Solution {
private:
    int solve(set<string>&st,string s,int low,int high,int zero,int one,string sz,string so,vector<int>&dp){
        if(s.size()>high)return 0;
        if(s.size()>=low&&s.size()<=high){
            if(st.find(s)==st.end()){
                st.insert(s);
              if(s.size()+zero>high&&s.size()+one>high)
                  return 1;
            }
           if(s.size()+zero>high&&s.size()+one>high)
               return 0;
        }
       int pickone=0,pickzero=0;
       if(s.size()+one<=high)
       pickone=solve(st,s+so,low,high,zero,one,sz,so,dp);
       if(s.size()+zero<=high)
       pickzero=solve(st,s+sz,low,high,zero,one,sz,so,dp);
       return pickone+pickzero;
    }
    int mod=1e9+7;
    long long optimize(vector<long long>&dp,int low,int high,int length,int zero,int one){
        if(length>=high)return 0;
        if(dp[length]!=-1)return dp[length];
        long long pickzero=optimize(dp,low,high,length+zero,zero,one)%mod; 
        if(length+zero>=low&&length+zero<=high)++pickzero;
        long long pickone=optimize(dp,low,high,length+one,zero,one)%mod;
        if(length+one>=low&&length+one<=high)++pickone;
        return dp[length]=(pickone+pickzero)%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
       //  set<string>st;
       //  string s;
       //  string so,sz;
       //  for(int i=0;i<zero;i++)sz.push_back('0');
       //  for(int i=0;i<one;i++)so.push_back('1');
       //  vector<int>dp(high+1,-1);
       //   solve(st,s,low,high,zero,one,sz,so,dp);
       // return st.size();
        vector<long long>dp(high+1,-1);
        return int(optimize(dp,low,high,0,zero,one));
        // int sum=0;
        // for(int i=low;i<=high;i++){
        //     sum+=dp[i];
        // }
        // return sum;
    }
};