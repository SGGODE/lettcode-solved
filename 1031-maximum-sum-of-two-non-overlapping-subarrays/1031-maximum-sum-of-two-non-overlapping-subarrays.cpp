class Solution {
private:
    int sub(vector<int>&nums,int index,int f,int s){
        if(f==0&&s==0)return 0;
        if(index==nums.size()&&(f!=0||s!=0))return -1e9;
        int notpick=sub(nums,index+1,f,s);
        int pick=-1e9;
        if(f!=0&&index+f<=nums.size()){
            int sum=0;
            for(int i=index;i<(index+f);i++){
                sum+=nums[i];
            }
            pick=max(pick,sum+sub(nums,index+f,0,s));
        }
        if(s!=0&&index+s<=nums.size()){
            int sum=0;
            for(int i=index;i<(index+s);i++){
                sum+=nums[i];
            }
            pick=max(pick,sum+sub(nums,index+s,f,0));
        }
        return max(pick,notpick);
    }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        return sub(nums,0,f,s);
    }
};