class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        int lm = -1;
        if(!left.empty())lm = *max_element(left.begin(),left.end());
        int rm = -1;
        if(!right.empty())rm = *min_element(right.begin(),right.end());
        if(rm!=-1)return max(lm,n-rm);
        if(lm==-1)return 0;
        return lm;
    }
};