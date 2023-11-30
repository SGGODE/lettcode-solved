class Solution {
public:
    int minimumOneBitOperations(int n) {
        // int cnt = 0;
        // while(n!=0){
        //     ++cnt;
        //     n>>=1;
        // }
        // return cnt;
        if (n==0) return 0;//base case
        int k=floor(log2(n));//31-__builtin_clz(n);
        int numOp=(1<<(k+1))-1;
        return numOp-minimumOneBitOperations(n^(1<<k));
    }
};