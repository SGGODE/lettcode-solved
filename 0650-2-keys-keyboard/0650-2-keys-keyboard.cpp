class Solution {
private:
    int sub(int n , int board , int cvalue){
        if(n == board)return 0;
        if(board > n)return 1e9;
        int ans = 1e9;
        if(board == 1 && cvalue == 1){
            ans = min(ans , 2 + sub(n , board + cvalue , cvalue));
        }else{
            ans = min(ans , 1 + sub(n , board + cvalue , cvalue));
            ans = min(ans , 2 + sub(n , 2 * board ,  board));
        }
        return ans;
    }
public:
    int minSteps(int n) {
        return sub(n,1,1);
    }
};