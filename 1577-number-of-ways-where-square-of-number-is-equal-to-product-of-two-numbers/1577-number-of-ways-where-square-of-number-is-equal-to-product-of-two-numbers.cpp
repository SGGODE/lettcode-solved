class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int cnt = 0;
        int mod = 1e9+7;
        map<long long,int>dp1;
        for(int i=0;i<nums1.size();i++){
            for(int j=i+1;j<nums1.size();j++){
                long long mul = nums1[i]*1LL*nums1[j];
                dp1[mul]++;
            }
        }
        map<long long,int>dp2;
        for(int i=0;i<nums2.size();i++){
            for(int j=i+1;j<nums2.size();j++){
                long long mul = nums2[i]*1LL*nums2[j];
                dp2[mul]++;
            }
        }
        for(auto&it:nums1){
            long long mul = it*1LL*it;
            if(dp2.count(mul)){
                cnt+=dp2[mul];
            }
        }
        for(auto&it:nums2){
           long long mul = it*1LL*it;
            if(dp1.count(mul)){
                cnt+=dp1[mul];
            }
        }
        return cnt;
    }
};