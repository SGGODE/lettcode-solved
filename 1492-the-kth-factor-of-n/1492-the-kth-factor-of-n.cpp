class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        while(k!=0&&i<=n){
            while(1){
                if(n%i==0){
                    --k;
                    if(k!=0)i++;
                    break;
                }
                ++i;
            }
        }
        return k==0?i:-1;
    }
};