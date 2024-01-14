class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>mp,mx;
        for(auto&it:word1)mp[it]++;
        for(auto&it:word2)mx[it]++;
        vector<int>num1,num2;
        vector<char>numx,numy;
        for(auto&it:mp){
            num1.push_back(it.second);
            numx.push_back(it.first);
        }
        for(auto&it:mx){
            num2.push_back(it.second);
            numy.push_back(it.first);
        }
        sort(num1.begin(),num1.end());sort(numx.begin(),numx.end());
        sort(num2.begin(),num2.end());sort(numy.begin(),numy.end());
        return num1==num2&&numx==numy;
    }
};