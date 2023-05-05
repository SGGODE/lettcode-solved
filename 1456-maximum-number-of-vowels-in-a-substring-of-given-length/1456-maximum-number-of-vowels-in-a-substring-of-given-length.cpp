class Solution {
private:
    bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }
public:
    int maxVowels(string s, int k) {
        map<char,int>mp;
        int maxelement=INT_MIN;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++; 
            int cnt=0;
            if(i>=k){
                --mp[s[i-k]];
            }
            for(auto &it:mp){
                if(isVowel(it.first))cnt+=it.second;
            }
            maxelement=max(maxelement,cnt);
        }
        return maxelement;
    }
};