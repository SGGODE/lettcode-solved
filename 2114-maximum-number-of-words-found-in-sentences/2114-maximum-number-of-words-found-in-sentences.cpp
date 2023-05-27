class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxcnt=0;
        for(int i=0;i<sentences.size();i++){
            string s=sentences[i];
            stringstream ss(s);
            string word;int cnt=0;
            while(ss>>word){
                ++cnt;
            }
            maxcnt=max(cnt,maxcnt);
        }
        return maxcnt;
    }
};