class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int cnt=0;
        int n=nums.size();
       map<vector<int>,int>mp;
        for(int i=0;i<n;i++){
            vector<int>v;int l=0;
            for(int j=i;j<n;j++){
                v.push_back(nums[j]);int div=0;
                for(auto it:v){
                    if(it%p==0)++div;
                }
                // vector<vector<int>>::iterator it;
                // it=find(vis.begin(),vis.end(),v);
                if(div<=k&&mp.find(v)==mp.end()){
                    ++cnt;
                    mp[v]++;
                }
            }
        }
        return cnt;
    }
};