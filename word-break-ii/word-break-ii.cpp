class Solution {
private:
    //int dp[301][1001];
    set<string>temp;
    bool sub(string&s,vector<string>&word,int index,int dictindex,string&res){
        if(index==s.size()){
            temp.insert(res);
            return 1;
        }
        if(dictindex==word.size())return 0;
       // if(dp[index][dictindex]!=-1)return dp[index][dictindex];
        bool ans = 0;
        ans = max(ans,sub(s,word,index,dictindex+1,res));
        if(s[index]==word[dictindex][0]){
            int j = 0;int id=index;
            while(id<s.size()&&j<word[dictindex].size()&&s[id]==word[dictindex][j]){
                ++j;++id;
            }
            if(id<=s.size()&&j==word[dictindex].size()){
                string c=res;
                if(id<s.size()){
                    c.append(word[dictindex]);
                    c.push_back(' ');
                }else{
                    c.append(word[dictindex]);
                }
                ans = max(ans,sub(s,word,id,0,c));
            }
        }
        return ans;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string res;
        sub(s,wordDict,0,0,res);
        vector<string>result(temp.begin(),temp.end());
        return result;
    }
};