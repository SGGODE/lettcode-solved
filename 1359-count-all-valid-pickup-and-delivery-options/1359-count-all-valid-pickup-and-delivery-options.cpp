class Solution {
public:
    long long mod=1e9+7;
    int countOrders(int n) {
       long long int sum = 1;
        for(int i=1;i<=n;i++){
            sum =(long long) (sum*(i*(2*i-1)))%mod;
        }
        return sum;
    }
};