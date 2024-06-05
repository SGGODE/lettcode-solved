class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
          int arr[26]={10001};
          for(int i=0;i<26;i++)arr[i]=10001;
          for(auto&it:words){
              int word[26]={0};
              for(auto&vt:it){
                  word[vt-'a']++;
              }
              for(int i=0;i<26;i++)arr[i]=min(arr[i],word[i]);
          }
         vector<string>result;
         for(int i=0;i<26;i++){
             char ch = 'a' + i;
             for(int j=0;j<arr[i];j++){
                 string str;
                 str += ch;
                 result.push_back(str);
             }
         }
        return result;
    }
};