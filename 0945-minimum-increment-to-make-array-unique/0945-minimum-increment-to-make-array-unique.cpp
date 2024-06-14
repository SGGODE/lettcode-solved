class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>unique;
        int last = -1;
        int count = 0;
        for(auto&it:nums){
            if(unique.count(it)){
                ++last;
                //cout<<last<<" "<<it<<endl;
                count+=abs(last-it);
                unique[last]++;
            }else{
                unique[it]++;
                last = it;
            }
           // cout<<count<<endl;
        }
        return count;
    }
};