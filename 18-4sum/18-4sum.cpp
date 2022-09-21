class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>v;
        vector<int>x;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long sum=(long)target-(long)nums[i]-nums[j];
                int s=j+1,e=n-1;
                while(s<e){
                    int get=nums[s]+nums[e];
                    if(get==sum){
                        v.insert({nums[i],nums[j],nums[s],nums[e]});
                        s++;
                        e--;
                    }else if(get>sum){
                        e--;
                    }
                    else{
                        s++;
                    }
                }
            }
        }
        vector<vector<int>>z(v.begin(),v.end());
        return z;
        
    }
};