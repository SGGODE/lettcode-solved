class Solution {
private:
    int dp[20001][6];
    int mod = 1e9+7;
    int sub(map<char,vector<char>>&res,char&last,int index,int n){
        if(index==n)return 1;
        int x = 0;
        if(last=='b')x=0;else if(last=='a')x=1;else if(last=='e')x=2;
        else if(last=='i')x=3;else if(last=='o')x=4;else x=5;
        if(dp[index][x]!=-1)return dp[index][x];
        long long int ans = 0;
        for(auto&it:res[last]){
            ans = (ans + sub(res,it,index+1,n))%mod;
        }
        return dp[index][x] = ans;
    }
public:
    int countVowelPermutation(int n) {
        map<char,vector<char>>mp;vector<char>temp{'a','e','i','o','u'};
        mp['b']=temp;mp['a'].push_back('e');vector<char>temp1{'a','i'};
        mp['e']=temp1;vector<char>temp2{'a','e','o','u'};
        mp['i']=temp2;vector<char>temp3{'i','u'};
        mp['o']=temp3;mp['u'].push_back('a');
        char ch = 'b';
        memset(dp,-1,sizeof(dp));
        return sub(mp,ch,0,n);
    }
};