class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // vector<string>::iterator it;
        // it = find(wordList.begin(),wordList.end(),endWord);
        // if(it==wordList.end())return 0;
        map<string,int>mp;
        for(auto&it:wordList){
            mp[it]++;
        }
        if(!mp.count(endWord))return 0;
        queue<pair<string,int>>pq;
        pq.push({beginWord,1});
        int res = INT_MAX;
        while(!pq.empty()){
            string str = pq.front().first;
            int turn = pq.front().second;
            pq.pop();
            if(str==endWord){
                res = min(res,turn);
                continue;
            }
            for(int i=0;i<str.size();i++){
                for(int j=0;j<26;j++){
                    string s=str;
                    s[i]='a'+j;
                    if(mp.count(s)){
                       // cout<<s<<endl;
                        mp.erase(s);
                        pq.push({s,turn+1});
                    }
                }
            }
        }
        return res==INT_MAX?0:res;
    }
};