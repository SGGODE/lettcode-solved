class Solution {
public:
    int pivotInteger(int n) {
        vector<int>res(n+1,0);
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum+=i;
            res[i]=sum;
        }
        for(int i=1;i<=n;i++)if(res[i]==(res[n]-res[i-1]))return i;
        
        return -1;
    }
};