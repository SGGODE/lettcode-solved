class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        int m=nums1.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(!mp.count(nums2[i]))mp[nums2[i]]=i;
        }
        vector<int>res(m,-1);
        for(int i=0;i<m;i++){
            bool flag=0;
            for(int j=0;j<n;j++){
                if(nums2[j]==nums1[i])flag=1;
                if(flag&&nums2[j]>nums1[i]){
                    res[i]=nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};