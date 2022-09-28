class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n=nums.size();
        if(n==1)
            return nums[0];
        int result=INT_MIN,mul=1;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mul*=nums[i];
            result=max(result,mul);
             if(mul==0)
                mul=1;
        }
        mul=1;
       for(int i=n-1;i>=0;i--){
            mul*=nums[i];
            result=max(result,mul);
             if(mul==0)
                mul=1;
        }
        return result;
    }
};