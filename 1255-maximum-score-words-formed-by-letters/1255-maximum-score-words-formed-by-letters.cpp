class Solution {
private:
    bool exist(int need[],int bol[]){
        for(int i=0;i<26;i++){
            if(need[i]>bol[i])return 0;
        }
        return 1;
    }
    int sub(vector<string>& words,vector<int>& score,int bol[],int index){
        if(index==words.size())return 0;
        int ans = 0;
        ans = max(ans,sub(words,score,bol,index+1));
        int need[26]={0};
        for(auto&it:words[index])need[it-'a']++;
        if(exist(need,bol)){
            int value = 0;
            for(int i=0;i<26;i++){
                bol[i]-=need[i];
                if(need[i]!=0)value+=(need[i]*score[i]);
            }
            ans = max(ans,value+sub(words,score,bol,index+1));
            for(int i=0;i<26;i++){
                bol[i]+=need[i];
            }
        }
        return ans;
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int bol[26]={0};
        for(auto&it:letters)bol[it-'a']++;
        return sub(words,score,bol,0);
    }
};