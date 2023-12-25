class Solution {
private:
    //dp to store all possible soluction answer from the given index i.
    int dp[101];
    //helper function who work on it.
    int sub(string&s,map<int,char>&mp,int index){
        //if we have done with all decode return 1;
        if(index==s.size())return 1;
        //not any possible char have starting with zero according to rule of problem.
        if(s[index]=='0')return 0;
        //we have already explore the state so return or just skip.
        if(dp[index]!=-1)return dp[index];
        //to store value of all possible ways from given index (index).
        int ans = 0;
        //to have a shorter form of decode ways i.e <=26;
        string x;
        //call all possible ways <=26;
        for(int i=index;i<s.size();i++){
            x.push_back(s[i]);
            if(stoi(x)<=26){
                ans += sub(s,mp,i+1);
            }else break;
        }
        //finally store it.
        return dp[index]=ans;
    }
public:
    int numDecodings(string s) {
        //dp init.
        memset(dp,-1,sizeof(dp));
        //creating a map to store 1-26 char i.e A-Z;
        map<int,char>mp;
        char ch = 'A';
        mp[1]=ch;
        for(int i=1;i<26;i++){
            mp[i+1]=ch+i;
        }
        //finally return the all possible ways to decode the string.
        return sub(s,mp,0);
    }
};