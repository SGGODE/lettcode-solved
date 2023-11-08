class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        long long int res1=abs(sx-fx);
        long long int res2=abs(sy-fy);
        long long int res3=max(res1,res2);
        if(res3>t || (res3==0 &&(t<2 and t>0)))return false;
        return true;
    }
};