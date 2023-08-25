class Solution {
private:
    //  bool sub1(vector<vector<vector<int>>>&dp,vector<bool>&vis,string&s1,string&s2,string&s3,int index1,int index2,int index3){
    //     if(index2==s2.size()){
    //         return 1;
    //     }
    //     if(index3==s3.size())return 0;
    //    // if(dp[index3][index1][index2]!=-1)return dp[index3][index1][index2];
    //     bool ans = sub1(dp,vis,s1,s2,s3,index1,index2,index3+1);
    //     if(!vis[index3]&&s2[index2]==s3[index3]){
    //         vis[index3]=1;
    //         ans=max(ans,sub1(dp,vis,s1,s2,s3,index1,index2+1,index3+1));
    //         vis[index3]=0;
    //     }
    //     return dp[index3][index1][index2]=ans;
    // }
    // bool sub(vector<vector<vector<int>>>&dp,vector<bool>&vis,string&s1,string&s2,string&s3,int index1,int index2,int index3){
    //     if(index1==s1.size()){
    //         return sub1(dp,vis,s1,s2,s3,0,0,0);
    //     }
    //     if(index3==s3.size())return 0;
    //    // if(dp[index3][index1][index2]!=-1)return dp[index3][index1][index2];
    //     bool ans = sub(dp,vis,s1,s2,s3,index1,index2,index3+1);
    //     if(s1[index1]==s3[index3]){
    //         vis[index3]=1;
    //         ans=max(ans,sub(dp,vis,s1,s2,s3,index1+1,index2,index3+1));
    //         vis[index3]=0;
    //     }
    //     return dp[index3][index1][index2]=ans;
    // }
    bool helper(vector<vector<vector<int>>>&dp,string s1,string s2,string s3,int i,int j,int k){
    if(i==-1 && j==-1 && k==-1){
        return true;
    }
    if(dp[i+1][j+1][k+1]!=-1)return dp[i+1][j+1][k+1];   
    if(i>=0 && j>=0 && k>=0 && s1[i]==s3[k] && s2[j]==s3[k]){
        return dp[i+1][j+1][k+1]=(helper(dp,s1,s2,s3,i-1,j,k-1) || helper(dp,s1,s2,s3,i,j-1,k-1));
    }
    else if(i>=0 && k>=0 && s1[i]==s3[k]){
        return dp[i+1][j+1][k+1]=helper(dp,s1,s2,s3,i-1,j,k-1);
    }
    else if(j>=0 && k>=0 && s2[j]==s3[k]){
        return dp[i+1][j+1][k+1]=helper(dp,s1,s2,s3,i,j-1,k-1);
    }
    else{
        return dp[i+1][j+1][k+1]=false;
    }
}
public:
    bool isInterleave(string s1, string s2, string s3) {
        int x=s3.size();
        int n=s1.size();
        int m=s2.size();
        if(x!=(n+m))return 0;
//         //if(!s3.empty())return 0;
//         int i=0,j=0;
//         vector<bool>vis(x,0);
//         for(int k=0;k<s3.size();k++){
//             if(!vis[k]&&s3[k]==s2[j]){
//                 j++;
//                 vis[k]=1;
//                // continue;
//             }
           
//         }
//         for(int k=0;k<s3.size();k++){
//             if(!vis[k]&&s3[k]==s1[i]){
//                 i++;
//                 vis[k]=1;
//                // continue;
//             }
           
//         }
//         return i==n&&j==m;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(x+1,-1)));
       // vector<bool>vis(x,0);
        //return sub(dp,vis,s1,s2,s3,0,0,0);
        return helper(dp,s1,s2,s3,n-1,m-1,x-1);
    }
};