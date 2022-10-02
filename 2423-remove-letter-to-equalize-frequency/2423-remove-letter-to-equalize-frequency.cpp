class Solution {
public:
    bool equalFrequency(string word) {
        vector<int>v(26,0);
        for(int i=0;i<word.size();i++){
            v[word[i]-'a']++;
        }
        for(int i=0;i<v.size();i++){
            set<int>s;
            vector<int>temp=v;
            if(temp[i]<=0){
                continue;
            }
            temp[i]--;
            for(auto it:temp){
                if(it>0)
                 s.insert(it);
            }
            if(s.size()==1){
                return 1;
            }
        }
        return 0;
    }
};