class Solution {
private:
    int dp[11][2][1000000];
    int sub(string&temp,int index,int tight,int cnt){
        if(index==temp.size())return cnt;
       if(dp[index][tight][cnt]!=-1)return dp[index][tight][cnt];
        int limit = 9;
        if(tight)limit=temp[index]-'0';
        int ans = 0;
        for(int i=0;i<=limit;i++){
            int ncnt=cnt;
            if(i==1)++ncnt;
            ans+=sub(temp,index+1,tight&(i==limit),ncnt);
        }
        return dp[index][tight][cnt]=ans;
    }
public:
    int countDigitOne(int n) {
        string temp = to_string(n);
        memset(dp,-1,sizeof(dp));
        return sub(temp,0,1,0);
    }
};