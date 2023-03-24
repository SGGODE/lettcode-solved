class Solution {
public:
    int mod=1000000007;
    int numSub(string s) {
    long long int total=0;
   long long int one=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ++one;
            }else{
                long long x=(one*(one+1))%mod;
                total+=x/2;
                one=0;
            }
        }
        if(one!=0)total+=(long long)(one*(one+1))/2;
        return total;
    }
};