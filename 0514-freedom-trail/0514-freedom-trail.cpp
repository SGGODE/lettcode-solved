class Solution {
private:
    vector<vector<int>>dp;
    int sub(string&ring,string&key,int ind,int kind,int n){
        if(kind==key.size())return 0;
        if(dp[ind][kind]!=-1)return dp[ind][kind];
        int ans = 1e9;
        for(int i=0;i<n;i++){
           if(ring[(ind+i)%n]==key[kind]){
               ans = min(ans,(i+1)+sub(ring,key,(ind+i)%n,kind+1,n));
           } 
        }
        for(int i=n-1;i>=0;i--){
           if(ring[(ind+i)%n]==key[kind]){
               ans = min(ans,((n-i)+1)+sub(ring,key,(ind+i)%n,kind+1,n));
           } 
        }
        return dp[ind][kind]=ans;
    }
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        dp.resize(n,vector<int>(m,-1));
        return sub(ring,key,0,0,n);
    }
};