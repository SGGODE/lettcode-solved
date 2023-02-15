class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string prefix="";
        string result;
        string x=strs[0];
        for(int i=0;i<strs[0].size();i++){
            prefix.push_back(x[i]);
            bool flag=1;
            for(int j=1;j<n;j++){
                string s=strs[j];
                for(int k=0;k<=i;k++){
                    if(s[k]==prefix[k])continue;
                    else{
                        flag=0;
                        break;
                    }
                }
            }
            if(flag){
                result.clear();
                result=prefix;
            }
        }
        return result;
    }
};