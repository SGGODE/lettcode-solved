class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        if(n==1)return 1;
        int mod = 1e9+7;
        long long sum = 0;
        map<int,int>mp;
        bool f = 0;
        for(int i=0;i<n-1;i++){
            if(i<n-1&&s[i]==s[i+1]){
                int j = i+1;
                while(j<n&&s[i]==s[j])++j;
                long long len = j-i;
                sum = (sum + static_cast<long long>((len*(len+1))/2))%mod;
                i=j-1;
                if(i==n-2){
                    sum++;
                }
            }else{
                sum++;
                if(i==n-2)sum++;
            }
        }
        return sum;
    }
};