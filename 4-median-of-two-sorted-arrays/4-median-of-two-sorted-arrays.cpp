class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        if(nums1.size()%2==0){
            int mid=nums1.size()/2;
            double ans=(nums1[mid]+nums1[mid-1])/2.0;
            return ans;
        }else{
            return nums1[nums1.size()/2];
        }
    }
};