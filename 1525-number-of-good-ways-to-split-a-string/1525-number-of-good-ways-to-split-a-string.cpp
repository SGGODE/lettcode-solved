class Solution {
private:
  //APPROACH:
    //  in this approach we compare the no of unique charter before the after the current position
    // if possible then we cut the string at that location if not then continue
 //dp to store.
 int dp[100001];
//helper function who workk on it.
 int sub(int index,vector<int>&prefix,vector<int>&sufix,int n){
    //any way no more cut possible at last position or end.
       if(index==n||index==n-1)return 0;
    //if the state already begin calculate.
       // if(dp[index]!=-1)return dp[index];
    //store current state both possibility if possible cut or don't cut.
        int ans = 0;
    //possibility if possible cut it.
        if(index+1<n&&prefix[index]==sufix[index+1])ans += 1 + sub(n,prefix,sufix,n);
    //don't cut it.
        ans += sub(index+1,prefix,sufix,n);
    //finally store the result.
    return dp[index]=ans;
 }
public:
    int numSplits(string s) {
        //intilize dp.
        memset(dp,-1,sizeof(dp));
        //size of string.
        int n = s.size();
        //prefix no of unique `char` array. 
            vector<int>prefix(n,0);
            set<char>st;
            for(int i=0;i<n;i++){
              st.insert(s[i]);
              prefix[i]=st.size();
            }
        //sufix no of unique `char` array.
            vector<int>sufix(n,0);
            set<char>stz;
            for(int i=n-1;i>=0;i--){
              stz.insert(s[i]);
              sufix[i]=stz.size();
            }
        //if there is only one unique charter in string then 
             if(prefix[n-1]==1)return n-1;
        //else 
        return sub(0,prefix,sufix,n);
    }
};