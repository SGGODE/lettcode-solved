class Solution {
private:
    void get(vector<vector<int>>&dp,vector<int>&res,int row,int col){
        int n = dp.size();
        int m = dp[0].size();
        while(row>=0&&col<m){
            if(dp[row][col]!=-1)res.push_back(dp[row][col]);
            --row;
            ++col;
        }
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // int n = nums.size();
        // int m = 0;
        // for(int i=0;i<nums.size();i++){
        //     int x = nums[i].size();
        //     m=max(m,x);
        // }
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<nums[i].size();j++){
        //         dp[i][j]=nums[i][j];
        //     }
        // }
        // vector<int>res;
        // for(int i=0;i<nums.size();i++){
        //     get(dp,res,i,0);
        // }
        // for(int j=1;j<m;j++){
        //     get(dp,res,n-1,j);
        // }
        // return res;
        map<int,vector<int>>dp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                dp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>res;
        for(auto&it:dp){
            vector<int>temp(it.second.begin(),it.second.end());
            reverse(temp.begin(),temp.end());
            for(auto&vt:temp)res.push_back(vt);
        }
        return res;
    }
};