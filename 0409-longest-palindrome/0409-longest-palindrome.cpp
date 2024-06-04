class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int>character;
        for(auto&it:s)character[it]++;
        int longestPal = 0;
        int odd = 0;
        for(auto&it:character){
            if(it.second%2){longestPal+=(it.second-1);odd=1;}
            else longestPal+=it.second;
        }
        return odd?longestPal+1:longestPal;
    }
};