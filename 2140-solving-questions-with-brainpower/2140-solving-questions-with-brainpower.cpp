class Solution {
private:
   // int mod=1e5+7;
   // int maxsum=INT_MIN;
    long long solve(vector<vector<int>>& questions,long long int index,int n,int sum,vector<long long int>&dp){
        if(index>=n){
            //maxsum=max(maxsum,sum);
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        long long notpick=-1e12;
        notpick =solve(questions,index+1,n,sum,dp);
        long long pick=-1e12;
        pick =questions[index][0] + (long long) solve(questions,index+1+questions[index][1],n,sum,dp);
        return dp[index]=max(notpick,pick);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
       int n=questions.size();
       vector<long long int>dp(n,-1);
      solve(questions,0,n,0,dp);
       //  long long int res=INT_MIN;
       //  for(int i=n-1;i>=0;i--){
       //     long long int sum=questions[i][0];
       //      if((i+questions[i][1]+1)>=n){
       //          if(i!=n-1)dp[i]=max(dp[i+1],sum);
       //          else dp[i]=sum;
       //      }else{
       //          if(i!=n-1)dp[i]=max(dp[i+1],sum+dp[(i+questions[i][1]+1)]);
       //          else dp[i]=sum+dp[(i+questions[i][1]+1)];
       //      }
       //     res=max(res,dp[i]);
       //  }
       //  return res;
        return *max_element(dp.begin(),dp.end());
      // return maxsum;
    }
};