class Solution {
private:
    int countNonMatchingChars(string&s,string&x) {
    int n=s.size();
    int j=0;
    int m=x.size();int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]==x[j])++j;   
        else ++cnt;
    }
    return cnt==1;
}
    static bool compareStringLength(string str1,string str2) {
    return str1.length() < str2.length();
}
public:
    int longestStrChain(vector<string>& words) {
        std::sort(words.begin(),words.end(),compareStringLength);
        int n=words.size();
        vector<int>dp(n,1);
      //  for(auto&it:words)cout<<it<<" ";
      //  cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int x=words[i].size();
                int y=words[j].size();
              //  cout<<words[i]<<" "<<words[j]<<" "<<countNonMatchingChars(words[i],words[j])<<endl;
               // cout<<words[j].size()-words[i].size()<<endl;
                if(x-y==1&&countNonMatchingChars(words[i],words[j])==1){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};