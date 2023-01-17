class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt1=0,cnt0=0;
        bool flag=1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                flag=0;
            }
            if(!flag){
                if(s[i]=='1')++cnt1;
                else ++cnt0;
            }
            if(cnt0>cnt1)cnt0=cnt1;
        }
        return cnt0;
    }
};