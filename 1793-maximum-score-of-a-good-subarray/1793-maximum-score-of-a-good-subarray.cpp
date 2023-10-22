class Solution {
private:



public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        //vector<int> st(2*n-1);
       // buildST(0,0,n-1,st,nums);
        if(n==1)return nums[0];
        int ans = 0;
        int s = k;
        int e = k;
        int temp = nums[k];
        while(s>0||e<n-1){
            if(s==0||(e<n-1&&nums[s-1]<nums[e+1])){
                e++;
            }else{
                s--;
            }
            temp = min({temp,nums[s],nums[e]});
            ans = max(ans,temp*((e-s)+1));
        }
        return ans;
    }
};