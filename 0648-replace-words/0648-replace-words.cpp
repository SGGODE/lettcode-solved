class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int>dict;
        for(auto&it:dictionary)dict[it]++;
        string result;
        stringstream ss(sentence);
        string word;
        while(ss>>word){
            bool root = 0;
            for(int i=0;i<word.size();i++){
                if(dict.count(word.substr(0,i+1))){
                    result.append(word.substr(0,i+1));
                    result.push_back(' ');
                    root=1;
                    break;
                }
            }
            if(!root){
                result.append(word);
                result.push_back(' ');
            }
        }
        result.pop_back();
        return result;
    }
};