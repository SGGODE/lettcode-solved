class Solution {
public:
    int reverse(int x) {
        int rev=0;
        long long int last=0;
        while(x!=0){
            if(last<INT_MIN/10 || last>INT_MAX/10)
                return 0;
            last=last*10+x%10;
            x=x/10;
        }
        return last;
    }
};