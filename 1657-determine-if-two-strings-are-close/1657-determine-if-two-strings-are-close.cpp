class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>mp1,mp2;
        for(int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
        }
        for(int i=0;i<word2.size();i++){
            mp2[word2[i]]++;
        }
        map<int,int>mp;
        for(auto it:mp1){
            mp[it.second]++;
        }
        for(auto it:mp2){
            mp[it.second]++;
        }
        vector<int>word0,word3;
        vector<char>word4,word5;
        for(auto it:mp1){
           word0.push_back(it.second);
        }
         for(auto it:mp2){
           word3.push_back(it.second);
        }
        for(auto it:mp1){
           word4.push_back(it.first);
        }
         for(auto it:mp2){
           word5.push_back(it.first);
        }
        sort(word0.begin(),word0.end());
        sort(word3.begin(),word3.end());
        sort(word4.begin(),word4.end());
        sort(word5.begin(),word5.end());
        // for(auto it:mp1){
        //     if(mp2.find(it.first)==mp2.end())return 0;
        // }
        // if(mp.size()==1)return 1;
        // for(auto it:mp){
        //     if(it.second%2==0)continue;
        //     else return 0;
        // }
        return word0==word3 && word4==word5;
    }
};