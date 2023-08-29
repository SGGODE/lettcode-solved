class Solution {
public:
    int maxDistToClosest(vector<int>&nums) {
        int n = nums.size();
        int td = INT_MIN;
        vector<int>prefix,suffix;
        int last = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                last=i;
            }
            prefix.push_back(last);
        }
        last=-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==1){
                last=i;
            }
            suffix.push_back(last);
        }
        reverse(suffix.begin(),suffix.end());
        for(int i=0;i<n;i++){
            if(prefix[i]==-1||suffix[i]==-1){
                if(suffix[i]==-1&&(i-prefix[i])>td){
                    td=i-prefix[i];
                }
                if(prefix[i]==-1&&(suffix[i]-i)>td){
                    td=suffix[i]-i;
                }
            }else{
                int d = min((i-prefix[i]),(suffix[i]-i));
                if(d>td)td=d;
            }
        }
        return td; 
    }
};