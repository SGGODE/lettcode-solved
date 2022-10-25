class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt=0;
        int sum=0;
        if(s.size()==1)return 1;
        for(int i=0;i<s.size();i++){
            set<char>ss;
            for(int j=i;j<s.length();j++){
                if(ss.find(s[j])==ss.end()){
                    ss.insert(s[j]);
                }else{
                    break;
                }
            }
            sum=ss.size();
            cnt=max(cnt,sum);
            ss.clear();
        }
        return cnt;
    }
};