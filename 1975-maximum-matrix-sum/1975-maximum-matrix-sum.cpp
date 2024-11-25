class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int ncount = 0 , sn = 1e9;
        for(auto & it : matrix){
            for(auto & vt : it){
                if(vt < 0)++ncount;
                sum += abs(vt);
                sn = min(sn , abs(vt));
            }
        }
        if(ncount % 2)return sum - 2*(sn);
        return sum;
    }
};