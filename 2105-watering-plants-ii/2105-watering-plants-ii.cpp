class Solution {
public:
    int minimumRefill(vector<int>&nums, int capacityA, int capacityB) {
        int s=0;
        int e=nums.size()-1;
        int cnt=0;
        int cA=capacityA;
        int cB=capacityB;
        while(s<=e){
            if(s==e){
                if(cA>=nums[s]||cB>=nums[e]){
                   // ++s;
                   // ++e;
                    break;
                }else{
                    ++cnt;
                    break;
                }
            }
            if(nums[s]<=cA){
                cA-=nums[s];
            }else{
                ++cnt;
                cA=capacityA;
                 cA-=nums[s];
            }
            if(nums[e]<=cB){
                cB-=nums[e];
            }else{
                ++cnt;
                cB=capacityB;
                cB-=nums[e];
            }
            ++s;
            --e;
            //cout<<cnt<<endl;
        }
        return cnt;
    }
};