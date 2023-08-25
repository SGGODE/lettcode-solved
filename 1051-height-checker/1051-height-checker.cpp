class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int cnt=0;
        vector<int>res(heights);
        sort(res.begin(),res.end());
        for(int i=0;i<res.size();i++){
            if(res[i]!=heights[i])++cnt;
        }
        return cnt;
    }
};