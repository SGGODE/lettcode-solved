class Solution {
public:
    bool checkPerfectNumber(int num) {
        int n=num/2;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(num%i==0)sum+=i;
        }
       // cout<<sum<<endl;
        return sum==num;
    }
};