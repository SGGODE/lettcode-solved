class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
         int n = str1.size() , m = str2.size();
         int i = 0 , j = 0;
         for(; i < n && j < m; i++){
            // cout<<str1[i]<<" "<<str2[j]<<endl;
             if(str1[i] == str2[j]){
                 ++j;
             }else if(str1[i] == 'z' && str2[j] == 'a'){
                 ++j;
             }else{
                int charVal = (str1[i] - 'a') + 1;
                char ch = 'a' + charVal;
                if(str2[j] == ch)++j;
             }
             //if(str1[i] == 'a' && str2[j] == 'a')++j;
         }
        //cout<<j<<endl;
        return j == m;
    }
};