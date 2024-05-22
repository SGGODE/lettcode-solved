class Solution {
private:
    vector<vector<string>>result;
    bool check(string&s){
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])return 0;
        }
        return 1;
    }
    void sub(string&s,vector<string>&res,int index){
        if(index==s.size()){
            result.push_back(res);
            return;
        }
        string substr;
        for(int i=index;i<s.size();i++){
            substr.push_back(s[i]);
            if(check(substr)){
                res.push_back(substr);
                sub(s,res,i+1);
                res.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>res;
        sub(s,res,0);
        return result;
    }
};