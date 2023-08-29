class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        map<int,int>mp;
        set<int>s;
        for(auto&it:nums){
            s.insert(it);
            mp[it]++;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(nums[0]);
        --mp[nums[0]];
        if(mp[nums[0]]==0){
            mp.erase(nums[0]);
            s.erase(nums[0]);
        }
        //*(my_set.rbegin());
        for(int i=1;i<nums.size()-1;i++){
            --mp[nums[i]];
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
                s.erase(nums[i]);
            }
            if(pq.top()<nums[i]&&nums[i]<*(s.rbegin())){
                return 1;
            }
            pq.push(nums[i]);
        }
        return 0;
    }
};