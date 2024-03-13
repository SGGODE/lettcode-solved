class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        int total = (n*(n+1))/2;
        for(int i=1;i<=n;i++){
            if(sum+i==(total-sum))return i;
            sum+=i;
        }
        return -1;
    }
};