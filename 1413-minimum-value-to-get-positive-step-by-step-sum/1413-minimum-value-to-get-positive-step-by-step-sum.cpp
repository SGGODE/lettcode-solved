class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int s = 1;
        int e = 1e4;
        int res=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;
            int sum=mid;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                if(sum<=0)break;
            }
            if(sum<=0){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return s;
    }
};