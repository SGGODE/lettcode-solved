class Solution {
public:
    string maximumOddBinaryNumber(string s) {
       string result;
       int cnt = 0;
       for(auto&it:s){
           if(it=='1')++cnt;
       }
       while(cnt>1){
           result.push_back('1');
           --cnt;
       }
       int n = s.size();
       while(result.size()<n-1)result.push_back('0');
       result.push_back('1');
       return result;
    }
};