class Solution {
private:
    int sub(int n,int val,int cnt){
        if(n==0&&cnt>=2)return 1;
        if(n==0&&cnt<2)return 0;
        if(val>n)return 0;
        int notpick = sub(n,val+1,cnt);
        int pick = 0;
        if(val<=n){
            pick = val * sub(n-val,val,cnt+1);  
        }
        return max(pick,notpick);
    }
public:
    int integerBreak(int n) {
        return sub(n,1,0);
    }
};