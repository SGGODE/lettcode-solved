class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>result;
        string word;
        stringstream ss(s1) , sss(s2);
        unordered_map<string,int> str1 , str2;
        while(ss>>word){
           str1[word]++; 
        }
        while(sss>>word){
           str2[word]++; 
        }
        for(auto&it:str1){
            if(!str2.count(it.first)&&it.second<2){
                result.push_back(it.first);
            }
        }
        for(auto&it:str2){
            if(!str1.count(it.first)&&it.second<2){
                result.push_back(it.first);
            }
        }
        return result;
    }
};