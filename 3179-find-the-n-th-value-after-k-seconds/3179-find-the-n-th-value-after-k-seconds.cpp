class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int mod = 1e9+7;
        vector<int>result(n,1);
        for(int i=0;i<k;i++){
            int sum = 1;
            for(int i=1;i<n;i++){
                result[i]=(result[i]+sum)%mod;
                sum = result[i];
            }
        }
        return result[n-1];
    }
};