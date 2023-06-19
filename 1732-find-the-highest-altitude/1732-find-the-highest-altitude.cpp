class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int res=0;
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            res=max(res,sum);
        }
        return res;
    }
};