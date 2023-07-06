class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int maxlen=0;
        map<int,vector<int>>mp;
        int index=0;
        for(auto&it:nums2){
            mp[it].push_back(index);
            ++index;
        }
        for(int i=0;i<n;i++){
            if(maxlen>=(n-i))break;
            if(mp.count(nums1[i])){
                for(auto&it:mp[nums1[i]]){
                   int k=i;int l=it;int cnt=0;
                    while(k<n&&l<m&&nums1[k]==nums2[l]){
                        ++k;
                        ++l;
                        ++cnt;
                    }
                    maxlen=max(maxlen,cnt);
                }
            }
        }
        return maxlen;
    }
};