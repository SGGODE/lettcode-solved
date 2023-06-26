class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        int m=nums1.size();
        map<int,int>mp;
        stack<int>s;
        vector<int>next(n,-1);
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                s.push({nums2[i]});
            }else{
                while(!s.empty()&&s.top()<nums2[i])s.pop();
                if(!s.empty())next[i]=s.top();
                s.push(nums2[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(!mp.count(nums2[i]))mp[nums2[i]]=next[i];
        }
        vector<int>res(m,-1);
        for(int i=0;i<m;i++){
            res[i]=mp[nums1[i]];
        }
        // for(int i=0;i<m;i++){
        //     for(int j=mp[nums1[i]]+1;j<n;j++){
        //         if(nums2[j]>nums1[i]){
        //             res[i]=nums2[j];
        //             break;
        //         }
        //     }
        // }
        return res;
    }
};