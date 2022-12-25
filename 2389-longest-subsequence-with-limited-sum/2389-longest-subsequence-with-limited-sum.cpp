class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
      sort(nums.begin(),nums.end());
        int n=queries.size();
      vector<int>res(n,0);
        for(int i=0;i<n;i++){
            int sum=0;int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(sum+nums[j]<=queries[i]){
                  sum+=nums[j];
                  ++cnt;
                }else break;
            }
            res[i]=cnt;
        }
        return res;
    }
};