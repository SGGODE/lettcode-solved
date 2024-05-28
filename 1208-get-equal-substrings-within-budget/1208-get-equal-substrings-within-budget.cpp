class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int maximum_length = 0;
        int j = 0;
        int i = 0;
        int currcost = 0;
        while(i<n){
            currcost+=abs(s[i]-t[i]);
            while(j<=i&&currcost>maxCost){
                currcost-=abs(s[j]-t[j]);
                j++;
            }
            maximum_length = max(maximum_length,(i-j)+1);
            i++;
        }
        return maximum_length;
    }
};