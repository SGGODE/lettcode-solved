class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        int n=word1.size();
        int m=word2.size();
        string res;
        while(i<n||j<m){
            if(i<n){
                res.push_back(word1[i]);
                ++i;
            }
            if(j<m){
                res.push_back(word2[j]);
                ++j;
            }
        }
        return res;
    }
};