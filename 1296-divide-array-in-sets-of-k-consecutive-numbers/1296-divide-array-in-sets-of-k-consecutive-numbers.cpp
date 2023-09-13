class Solution {
private:
    // bool sub(vector<int>&nums,int index,int k){
    //     if(index==nums.size())return 1;
    //     bool ans = 0;
    //     int cnt = 0;
    //     int prev = nums[index];
    //     int i = 0;
    //     for(i=index+1;i<nums.size()&&cnt<k;i++){
    //         if(nums[i]==prev+1){
    //             ++cnt;
    //             prev=nums[i];
    //         }
    //     }
    //     if(cnt==k){
    //         for(int i = index+1;i<)
    //     }
    //     return ans;
    // }
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
       // vector<
       //  int n = nums.size();
       //  sort(nums.begin(),nums.end());
       //  vector<bool>vis(n,0);
       // return sub(nums,0,k);
        map<int,int>mp;
        for(auto&it:nums)mp[it]++;
        while(!mp.empty()){
            int node = mp.begin()->first;
            for(int i=node;i<node+k;i++){
                if(!mp.count(i))return 0;
                --mp[i];
                if(mp[i]==0)mp.erase(i);
            }
        }
        return 1;
    }
};