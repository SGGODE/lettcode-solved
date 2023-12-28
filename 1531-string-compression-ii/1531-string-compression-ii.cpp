// class Solution {
// private:
//    map<string,int>mp;
//     int cal(string&temp){
//         if(temp.size()<=1)return 1;
//         string cnt;
//         map<char,int>mp;
//         for(int i=1;i<temp.size();i++){
           
//         }
//         //cout<<cnt<<endl;
//         return cnt.size();
//     }
//     int sub(string&s,string&temp,int index,int k){
//         if(index==s.size()){
//             //cout<<temp<<endl;
//             return cal(temp);
//         }
//         string str = temp+"-"+to_string(index)+"_"+to_string(k);
//         if(mp.count(str))return mp[str];
//         int ans = 1e9;
//         temp.push_back(s[index]);
//         ans = min(ans,sub(s,temp,index+1,k));
//         temp.pop_back();
//         if(k!=0)ans = min(ans,sub(s,temp,index+1,k-1));
//         return mp[str]=ans;
//     }
// public:
//     int getLengthOfOptimalCompression(string s, int k) {
//         //memset(dp,-1,sizeof(dp));
//         if(s.size()==k)return 0;
//         string temp;
//         int res = sub(s,temp,0,k);
//         return res;
//     }
// };
class Solution {
    const static int N = 127;

    // dp[left][k] means the minimal coding size for substring 
    // s[left:] and removing at most k chars
    int dp[N][N];

    string str;
    int n;

    // get length of digit
    inline int xs(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }

    int solve(int left, int k) {
        if(k < 0) return N;  // invalid, return INF
        if(left >= n or n - left <= k) return 0;  // empty

        int& res = dp[left][k];
        if(res != -1) return res;
        res = N;

        int cnt[26] = {0};
        // we try to make s[left:j] (both inculded) as one group,
        // and all chars in this group should be the same.
        // so we must keep the most chars in this range and remove others
        // the range length is (j - left + 1)
        // and the number of chars we need to remove is (j - left + 1 - most)
        for(int j = left, most = 0; j < n; j++) {
            most = max(most, ++cnt[str[j] - 'a']);  // most = max(count(s[left:j])
            res = min(res, 1 + xs(most) + solve(j + 1, k - (j - left + 1 - most)));
        }
        return res;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        str = s;
        n = s.size();
        return solve(0, k);
    }
};