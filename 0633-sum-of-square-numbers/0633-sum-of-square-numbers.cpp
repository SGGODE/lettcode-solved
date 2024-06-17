class Solution {
public:
    bool judgeSquareSum(int c) {
        if(!(c&c-1))return 1;
        unordered_map<int,int>square;
        for(int i=0;i<=sqrt(c);i++){
            if(square.count(c-(i*i)))return 1;
            square[(i*i)]++;
        }
        return 0;
    }
};