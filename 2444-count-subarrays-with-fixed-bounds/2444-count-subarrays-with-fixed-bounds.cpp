class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // long long int cnt=0;
        // for(int i=0;i<nums.size();i++){
        //     vector<int>x;
        //     for(int j=i;j<nums.size();j++){
        //         x.push_back(nums[j]);
        //         int mi=*min_element(x.begin(),x.end());int m=*max_element(x.begin(),x.end());
        //         if(m==maxK && mi==minK)
        //             cnt++;
        //     }
        // }
        // return cnt;
        // vector<int>v;int cnt=0;
        // for(int i=0;i<nums.size();i++){
        //     v.push_back(nums[i]);
        //      int mi=*min_element(v.begin(),v.end());int m=*max_element(v.begin(),v.end());
        //     if(m==maxK && mi==minK)
        //             cnt++;
        // }
        // if()
        // return cnt;
        long badi=-1,jmin=-1,jmax=-1,res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<minK||nums[i]>maxK){
                badi=i;
            }if(nums[i]==minK) jmin=i;
             if(nums[i]==maxK) jmax=i;
            res+=max(0L,min(jmin,jmax)-badi);
        }
        return res;
    }
};