class Solution {
private:
    void allpossiblesub(int n,string num,int index,string s,vector<string>&v){
        if(index>=n){
            v.push_back(s);
            return;
        }
        s.push_back(num[index]);
        index+=1;
        allpossiblesub(n,num,index,s,v);
        s.pop_back();
        index+=1;
        allpossiblesub(n,num,index,s,v);
    }
    void printSubsequence(string input, string output,vector<string>&v){
    if (input.empty()) {
        //cout << output << endl;
        v.push_back(output);
        return;
    }
    printSubsequence(input.substr(1), output + input[0],v);
    printSubsequence(input.substr(1), output,v);
}
 //   int n,m;int dp[n][m]={-1};
 int maxstr(string &s1,string &s2,int index1,int index2,vector<vector<int>>&dp){
     if(index1<0||index2<0)return 0;
     if(dp[index1][index2]!=-1)return dp[index1][index2];
     if(s1[index1]==s2[index2]){
         return dp[index1][index2]=1+maxstr(s1,s2,index1-1,index2-1,dp);
     }
     return dp[index1][index2]=max(maxstr(s1,s2,index1-1,index2,dp),maxstr(s1,s2,index1,index2-1,dp));
 }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      //  if(n>m){
      //      int j=0;int cnt=0;
      //      for(int i=0;i<n&&j<m;i++){
      //          if(text1[i]==text2[j]){
      //              cnt++;j++;
      //          }else j++;
      //      }
      //      return cnt;
      //  }else{
      //      int j=0;int cnt=0;
      //      for(int i=0;i<m&&j<n;i++){
      //          if(text2[i]==text1[j]){
      //              cnt++;j++;
      //          }else j++;
      //      }
      //      return cnt; 
      //  }
       // vector<string>s1,s2;string x="";
        //allpossiblesub(n,text1,0,"",s1);
       // printSubsequence(text1,"",s1);
       // printSubsequence(text2,"",s2);
        //for(auto it:s1)cout<<it<<" ";cout<<endl;
        //allpossiblesub(m,text2,0,"",s2);
        //for(auto it:s2)cout<<it<<" ";cout<<endl;
        //cout<<endl;
        // map<string,int>mp;
        //  for(auto it:s1)mp[it]++;
        // map<string,int>mpx;
        //   for(auto it:s2)mpx[it]++;
        // int cntmax=0;
        // for(auto it:mp){
        //     if(mpx.find(it.first)!=mpx.end()){
        //         int size=it.first.size();
        //         cntmax=max(cntmax,size);
        //     }
        // }
        // return cntmax;
        return maxstr(text1,text2,n-1,m-1,dp);
    }
};