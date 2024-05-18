class Solution {
private:
bool compare(unordered_map<char,int>&pattern,unordered_map<char,int>&substr){
    for(auto&it:pattern){
       if(!(substr.count(it.first)&&it.second<=substr[it.first]))return 0;
    }
  return 1;
}
public:
    string minWindow(string str, string arr) {
        int n = str.size();
        unordered_map<char,int>pattern;
        for(auto&it:arr)pattern[it]++;
        int j = 0 , len = INT_MAX;
        int windowend=-1 , windowstart=-1;
        unordered_map<char,int>substr;
        for(int i=0;i<n;i++){
            substr[str[i]]++;
            while(compare(pattern,substr)&&j<=i){
                if(len>(i-j)+1){
                   len = (i-j)+1;
                   windowstart=j,windowend=i;
                }
                --substr[str[j]];
                if(substr[str[j]]==0)substr.erase(str[j]);
                j++;
             }
        }
        string result="";
        if(windowstart!=-1)for(int i=windowstart;i<=windowend;i++)result.push_back(str[i]);
        return result;
    }
};