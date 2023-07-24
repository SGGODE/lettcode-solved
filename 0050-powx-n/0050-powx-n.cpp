class Solution {
public:
    double myPow(double x, int n) {
        double res = x;
      //   if(n==1)return x;
      //  // n=abs(n);
      //   if(n>0){
      //   n--;
      //   while(n!=0){
      //       res*=x;
      //       n--;
      //   }}else{
      //       int t=n;
      //      while(t!=0){
      //          x/=n;
      //          t--;
      //      } 
      //   }
      // //  if(n<0)return -res;
      //   return res;
        return pow(x,n);
    }
};