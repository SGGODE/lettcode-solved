class Solution {
public:
    string removeStars(string s) {
        string res;
        int n=s.size();
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(cnt==0&&s[i]!='*'){
                res.push_back(s[i]);
            }else{
                if(s[i]=='*')++cnt;
                else --cnt;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};