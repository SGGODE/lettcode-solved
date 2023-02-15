class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
         int n=s.size();
        // vector<bool>vis(n,0);
        int cnt=0;
        int j=0;
        int m=g.size();
        for(int i=0;i<n;i++){
            if(j<m&&s[i]>=g[j]){
                ++cnt;
                ++j;
            }
            
        }
        return cnt;
    }
};