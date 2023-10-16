class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int m = n;
        while(n--){
            vector<int>temp;
            for(int i=1;i<m;i++){
                temp.push_back((nums[i]+nums[i-1])%10);
            }
            nums=temp;
            //for(auto&it:temp)cout<<it<<" ";
            //cout<<endl;
            --m;
        }
        return nums[0];
    }
};