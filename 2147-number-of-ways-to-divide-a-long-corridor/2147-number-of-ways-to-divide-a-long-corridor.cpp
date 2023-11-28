class Solution {
private:
    int mod = 1e9+7;
    int dp[100001][3];
    int sub(string&s,vector<int>&res,int index,int cnt){
        if(index==res.size()){
            return cnt==2;
        }
        if(cnt>2)return 0;
        if(dp[index][cnt]!=-1)return dp[index][cnt];
        int cut = 0;
        if(s[index]=='P'){
            cut = (cut + sub(s,res,index+1,cnt))%mod;
            if(cnt==2){
                cut = (cut + sub(s,res,index+1,0))%mod;
            }
        }else{
            if(cnt==1){
                cut = (cut + sub(s,res,index+1,0)+sub(s,res,index+1,cnt+1))%mod;
            }else cut = (cut + sub(s,res,index+1,cnt+1))%mod;
        }
        return dp[index][cnt]=cut;
    }
public:
    int numberOfWays(string corridor) {
        memset(dp,-1,sizeof(dp));
        int n = corridor.size();
        vector<int>res;
        int cnt = 0;
        for(auto&it:corridor){
            if(it=='S')++cnt;
            res.push_back(cnt);
        }
        if(res[n-1]==2)return 1;
        if(res[n-1]%2!=0)return 0;
        return sub(corridor,res,0,0);
    }
};