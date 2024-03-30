class Solution {
private:
    int countsubs(vector<int>& nums, int k){
        int n = nums.size();
        int cnt =0;
        int i=0,j=0;
        map<int,int>mp;
        while(i<n){
            mp[nums[i]]++;
            while(j<=i&&mp.size()>k){
                --mp[nums[j]];
                if(mp[nums[j]]==0)mp.erase(nums[j]);
                ++j;
            }
            cnt += (i-j)+1;
            i++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countsubs(nums,k)-countsubs(nums,k-1);
    }
};