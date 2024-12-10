class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int maxlen = 0 , maxfreq = 0;
        string result;
        unordered_map<string , int> mp;
        for(int i = 0; i < n; i++){
            string t;
            for(int j = i; j < n; j++){
                if(s[j] != s[i])break;
                t.push_back(s[j]);
                mp[t]++;
            }
        }
        for(auto&it : mp){
            if(it.second >= 3){
                if(maxlen <= it.first.size()){
                    result = it.first;
                    maxlen = it.first.size();
                }
            }
        }
        return maxlen == 0 ? -1 : maxlen;
    }
};