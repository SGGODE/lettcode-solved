class Solution {
 map<char,int>mp;
 bool compareInterval(string i1, string i2){
    return (i1 < i2);
}
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // int j=0;
        // for(auto it:order){
        //     mp[it]=++j;
        // }
        // vector<string>dump(words);
        // sort(dump.begin(),dump.end(),compareInterval);
        // return dump==words;
        int mapping[26];
        for (int i = 0; i < 26; i++)
            mapping[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = mapping[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
};