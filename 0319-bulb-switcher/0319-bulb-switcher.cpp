class Solution {
    public:
    int bulbSwitch(int n) {
        int cnt=0;
        int i=1;
        while(i*i<=n){
            i++;
            ++cnt;
        }
        return cnt;
    }
};