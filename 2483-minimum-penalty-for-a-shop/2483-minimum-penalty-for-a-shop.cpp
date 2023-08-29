class Solution {
public:
    int bestClosingTime(string nums) {
        int n = nums.size();
        vector<int>psum,nsum;
        int psu=0,nsu=0;
        for(auto&it:nums){
            if(it=='Y')++psu;
            else ++nsu;
            psum.push_back(psu);
            nsum.push_back(nsu);
        }
        int minp=INT_MAX;
        int index=-1;
        for(int i=0;i<=nums.size();i++){
            if(i>=1){
                int lost = nsum[i-1];
                lost+=psum[n-1]-psum[i-1];
                if(lost<minp){
                    minp=lost;
                    index=i;
                }
            }else{
                if(psum[n-1]<minp){
                    minp=psum[n-1];
                    index=0;
                }
            }
        }
        return index;
    }
};