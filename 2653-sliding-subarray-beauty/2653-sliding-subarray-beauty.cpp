class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res(n - k + 1);
        map<int,int>mp;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            mp[num]++;
            if (i >= k) {
                int out= nums[i - k];
                mp[out]--;
                if (mp[out] == 0) {
                    mp.erase(out);
                }
            }
            if (i >= k - 1) {
                int cnt = 0;
                int val = 0;
                for (auto it : mp) {
                    cnt += it.second;
                    if (cnt >= x) {
                        val = it.first;
                        break;
                    }
                }
               if(val<0)res[i - k + 1]=val;
               else res[i - k + 1]=0;
            }
        }

        return res;
    }
};