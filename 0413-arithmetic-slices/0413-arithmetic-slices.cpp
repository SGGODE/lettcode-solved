class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt=0;
        int last=0;
        int mlen=0;
        if(nums.size()>=3){
        for(int i=0;i<nums.size()-2;i++){
            int d=nums[i]-nums[i+1];
            int len=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j-1]-nums[j]==d){
                    ++len;
                }else{
                   if(len>=3)mlen=max(mlen,len);
                    d=nums[j-1]-nums[j];
                    len=1;
                }
                if(len>=3)++cnt;
            }
          }
        }
        return cnt;
    }
};