class Solution {
private:
    int dp[40];
   int fibo(int *dp,int n){
       if(n==1||n==2)
           return 1;
       if(dp[n]!=-1)
           return dp[n];
       dp[n]=fibo(dp,n-1)+fibo(dp,n-2);
       return dp[n];
   } 
public:
    int fib(int n){
        if(n<1)
            return 0;
        for(int i=0;i<40;i++){
            dp[i]=-1;
        }
        return fibo(dp,n);
    }
};