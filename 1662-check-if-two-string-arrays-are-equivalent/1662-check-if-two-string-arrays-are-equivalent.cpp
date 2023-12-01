class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string res1,res2;
        for(auto&it:word1){
            res1.append(it);
        }
        for(auto&it:word2){
            res2.append(it);
        }
        return res1==res2;
    }
};