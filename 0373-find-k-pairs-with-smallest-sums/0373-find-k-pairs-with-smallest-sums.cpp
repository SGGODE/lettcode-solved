class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>res;
        int n=nums1.size();
        int m=nums2.size();
         priority_queue<pair<int,pair<int,int>>>pq;
        // map<int,int>mp;
        // for(auto&it:nums1)mp[it]++;
        // nums1.clear();
        // for(auto&it:mp)nums1.push_back(it.first);
        // sort(nums1.begin(),nums1.end());
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         // int temp=mp[nums1[i]];
        //         // while(temp--){
        //          if(pq.size()<k)pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
        //          else if(pq.top().first>nums1[i]+nums2[j]){
        //              pq.pop();
        //              pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
        //          }else break;
        //            // --k;
        //        // }
        //     }
        // }
        priority_queue<int>pqx,pqy;
        for(int i=0;i<min(n,k);i++){
            pqx.push({nums1[i]});
            if(pqx.size()>k)pqx.pop();
        }
        for(int i=0;i<min(m,k);i++){
            pqy.push({nums2[i]});
            if(pqy.size()>k)pqy.pop();
        }
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        while(!pqx.empty()){
            pq1.push(pqx.top());
            pqx.pop();
        }
         while(!pqy.empty()){
            pq2.push(pqy.top());
            pqy.pop();
        }
       // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        while(!pq1.empty()){
            priority_queue<int,vector<int>,greater<int>>pqx(pq2);
            bool flag=0;
            while(!pqx.empty()){
                 if(pq.size()<k)pq.push({pq1.top()+pqx.top(),{pq1.top(),pqx.top()}});
                 else if(pq.top().first>pq1.top()+pqx.top()){
                     pq.pop();
                     pq.push({pq1.top()+pqx.top(),{pq1.top(),pqx.top()}});
                 }else{
                     flag=1; break;
                 }
                pqx.pop();
            }
            pq1.pop();
        }
         while(!pq.empty()&&k--){
            res.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};