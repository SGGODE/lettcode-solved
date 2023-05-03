class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>v1;
        set<int>v2;
        set<int>st1(nums1.begin(),nums1.end());
        set<int>st2(nums2.begin(),nums2.end());
        int n=nums1.size();int m=nums2.size();
        for(int i=0;i<n;i++){
            if(st2.find(nums1[i])==st2.end()){
                v1.insert(nums1[i]);
            }
        }
         for(int i=0;i<m;i++){
            if(st1.find(nums2[i])==st1.end()){
                v2.insert(nums2[i]);
            }
        }
        vector<int>x1(v1.begin(),v1.end());
        vector<int>z2(v2.begin(),v2.end());
        return {x1,z2};
    }
};