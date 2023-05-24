class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>res;
        for(int i=0;i<nums1.size();i++){
            res.push_back({nums2[i],nums1[i]});
        }
        sort(res.begin(),res.end());
        reverse(res.begin(),res.end());
        long long int maxsum=INT_MIN;
        long long int sum=0;
        priority_queue<long long int,vector<long long int>,greater<long long int>>pq;
        for(int i=0;i<res.size();i++){
            if(i>=k-1){
                sum+=res[i].second;
                pq.push(res[i].second);
                maxsum=(long long)max(maxsum,(sum*res[i].first));
                sum-=pq.top();
                pq.pop();
            }
            else{
                sum+=res[i].second;
                pq.push(res[i].second);
            }
        }
        return maxsum;
    }
};