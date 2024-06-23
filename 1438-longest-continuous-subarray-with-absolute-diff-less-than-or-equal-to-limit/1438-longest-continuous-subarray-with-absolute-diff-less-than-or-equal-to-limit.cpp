class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int j = 0;
        unordered_map<int,int>freq;
        set<int>s;
        int mlen = 0;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            s.insert(nums[i]);
            auto it = s.begin() , vt = s.end();
            --vt;
            int start = *it , end = *vt;
            while((end - start) > limit){
                --freq[nums[j]];
                if(freq[nums[j]]==0)s.erase(nums[j]);
                j++;
                auto it = s.begin() , vt = s.end();
                --vt;
                start = *it , end = *vt;
            }
            mlen = max(mlen,(i-j)+1);
        }
        return mlen;
    }
};