class Solution {
public:
    int wateringPlants(vector<int>&nums, int capacity) {
        int step=0;
        int cC=capacity;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=cC){
                cC-=nums[i];
                ++step;
            }else{
                step+=i;
                step+=(i+1);
                cC=capacity;
                cC-=nums[i];
            }
        }
        return step;
    }
};