class Solution {
private:
    vector<string>result;
    void sub(string&s,unordered_map<string,int>&words,string breakedString,int index){
        if(index==s.size()){
            breakedString.pop_back();
            //cout<<"yes"<<endl;
            result.push_back(breakedString);
            return;
        }
        string runningStr;
        for(int i=index;i<s.size();i++){
            runningStr.push_back(s[i]);
            if(words.count(runningStr)){
                sub(s,words,breakedString+runningStr+" ",i+1);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>words;
        for(auto&it:wordDict)words[it]++;
        string breakedString;
        sub(s,words,breakedString,0);
        return result;
    }
};