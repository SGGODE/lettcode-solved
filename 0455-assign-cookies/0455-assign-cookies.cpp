class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int j = 0;
        int cnt = 0;
        for(int i=0;i<s.size()&&j<g.size();i++){
            if(s[i]>=g[j]){
                ++cnt;
                ++j;
            }
        }
        return cnt;
    }
};