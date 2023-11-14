class Solution {
private:
   
public:
    int countPalindromicSubsequence(string s) {
       map<char,int>start;
       map<char,int>end;
       for(int i=0;i<s.size();i++){
           if(start.count(s[i])){
               end[s[i]]=i;
           }else{
               start[s[i]]=i;
           }
       }
        int cnt=0;
        for(auto&it:start){
            if(end.count(it.first)){
                int last = end[it.first];
                set<char>temp(s.begin()+(it.second+1),s.begin()+(last));
                cnt+=temp.size();
            }
        }
        return cnt;
    }
};