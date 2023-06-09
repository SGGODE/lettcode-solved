class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ch;
        map<char,int>mp;
        for(int i=0;i<=25;i++){
            char res='a';
            mp[res+i]=i+1;
        }
       // for(auto &it:mp)cout<<it.first<<" "<<it.second<<endl;
       // return 'c';
        map<char,int>present;
        for(auto &it:letters)present[it]++;
        int x=mp[target];
        for(int i=x;i<=26;i++){
            char ch='a';
            if(present.count(ch+i))return ch+i;
        }
        return letters[0];
    }
};