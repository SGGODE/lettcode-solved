class Solution {
public:
    int countEven(int num) {
        int cnt=0;
        for(int i=1;i<=num;i++){
            int sum=0;
            int numx=i;
            while(numx!=0){
                int last=numx%10;
                sum+=last;
                numx=numx/10;
            }
            if(sum%2==0)++cnt;
        }
        return cnt;
    }
};