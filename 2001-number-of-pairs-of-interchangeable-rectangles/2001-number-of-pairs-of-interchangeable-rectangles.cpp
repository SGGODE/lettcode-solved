class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>&nums) {
        long long cnt = 0;
        map<double,int>mp;
        for(int i=0;i<nums.size();i++){
            double div = (double)((double)nums[i][0]/(double)nums[i][1]);
           // cout<<div<<endl;
            if(mp.count(div))cnt=(long long)cnt+mp[div];
            mp[div]++;
        }
        return cnt;
    }
};