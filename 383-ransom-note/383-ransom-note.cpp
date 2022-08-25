class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
       // unordered_map<char,int> mm;
        for(int i=0;i<magazine.length();i++){
            mp[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.length();i++){
            if(mp.find(ransomNote[i])!=mp.end()){
                if(mp[ransomNote[i]]==0)
                    return 0;
                mp[ransomNote[i]]--;
            }
            else
                return 0;
        }
        return 1;
    }
};