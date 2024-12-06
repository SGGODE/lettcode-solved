class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int , int>mp;
        for(auto & it : banned)mp[it]++;
        int sum = 0 , count = 0;
        for(int i = 1; i <= n && sum <= maxSum; i++){
            if(!mp.count(i) && sum + i <= maxSum){
                sum += i;
                ++count;
            }
        }
        return count;
    }
};