class Solution {
public:
    int maxDepth(string s) {
      int curr_max=0;
      int all_max=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                curr_max++;
            }
            if(s[i]==')'){
                curr_max--;
            }
            all_max=max(all_max,curr_max);
        }
        return all_max;
    }
};