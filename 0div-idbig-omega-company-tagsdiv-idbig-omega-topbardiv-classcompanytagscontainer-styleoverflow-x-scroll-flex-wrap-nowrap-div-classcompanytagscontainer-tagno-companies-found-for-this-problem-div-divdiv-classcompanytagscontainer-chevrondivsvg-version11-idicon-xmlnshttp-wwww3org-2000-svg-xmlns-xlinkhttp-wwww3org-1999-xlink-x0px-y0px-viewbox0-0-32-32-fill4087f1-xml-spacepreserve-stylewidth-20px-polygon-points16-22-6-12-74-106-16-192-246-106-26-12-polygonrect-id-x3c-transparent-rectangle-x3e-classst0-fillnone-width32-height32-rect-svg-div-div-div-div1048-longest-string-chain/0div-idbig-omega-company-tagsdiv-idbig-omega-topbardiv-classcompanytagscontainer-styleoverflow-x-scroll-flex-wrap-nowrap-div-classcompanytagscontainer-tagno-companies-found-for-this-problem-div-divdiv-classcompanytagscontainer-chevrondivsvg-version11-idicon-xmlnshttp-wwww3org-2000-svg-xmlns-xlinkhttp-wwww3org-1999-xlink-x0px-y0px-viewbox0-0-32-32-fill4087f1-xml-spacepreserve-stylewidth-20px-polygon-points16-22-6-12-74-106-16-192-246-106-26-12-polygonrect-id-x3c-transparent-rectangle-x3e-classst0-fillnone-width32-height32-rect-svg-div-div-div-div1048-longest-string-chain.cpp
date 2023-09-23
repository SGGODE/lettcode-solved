class Solution {
private:
    bool static comp(string&x,string&y){
        return x.size()<y.size();
    }
    bool check(string&a,string&b){
        if(a.size()+1!=b.size())return 0;
        int j=0;
        for(int i=0;i<b.size();i++){
            if(b[i]==a[j])++j;
        }
        return j>=a.size();
    }
    int dp[1001][3];
    int sub(vector<string>&nums,string&temp,int index,int start){
        if(index==nums.size())return 0;
        if(dp[index][start+1]!=-1)return dp[index][start+1];
        int notpick = sub(nums,temp,index+1,start);
        int pick = 0;
        if(start==-1){
            pick = 1 + sub(nums,nums[index],index+1,1);
        }else{
            if(check(temp,nums[index])){
                pick = max(pick,1+sub(nums,nums[index],index+1,start));
            }
        }
        return dp[index][start+1]=max(pick,notpick);
    }
public:
    int longestStrChain(vector<string>& words) {
        int len = 0;
       // memset(dp,1,sizeof(dp));
        sort(words.begin(),words.end(),comp);
        // for(auto&it:words)cout<<it<<" ";
        // cout<<endl;
        // // for(int i=0;i<words.size();i++){
        // //     string x =words[i];int clen=1;
        // //     for(int j=i+1;j<words.size();j++){
        // //          if(x.size()+1==words[j].size()){
        // //              int cnt = 0;int m=0;int k =0;
        // //              for(k=0;k<words[j].size()&&m<x.size();k++){
        // //                  if(words[j][k]!=x[m]){
        // //                      ++cnt;
        // //                  }else{
        // //                      ++m;
        // //                  }
        // //              }
        // //             if(k!=words[j].size())cnt+=(words[j].size()-k);
        // //              if(cnt==1){
        // //                  x=words[j];
        // //                  ++clen;
        // //              }
        // //          }
        // //     }
        // //     len =max(len,clen);
        // // }
        // string temp;
        // return sub(words,temp,0,-1);
        int n = words.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int x = words[i].size();int y=words[j].size();
                if(x-y==1&&check(words[j],words[i])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};