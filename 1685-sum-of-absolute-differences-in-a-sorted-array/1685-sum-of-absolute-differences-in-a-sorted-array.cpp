class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
       long long int sum = 0;
       int mod = 1e9+7;
        vector<int>prefix;
       for(auto&it:nums){
            sum=(sum+it);
           prefix.push_back(sum);
       }
       vector<int>suffix;
        sum = 0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            suffix.push_back(sum);
        }
        reverse(suffix.begin(),suffix.end());
       int n = nums.size();
       vector<int>res(n,0);
       for(int i=0;i<nums.size();i++){
           if(i<n-1){
               res[i]=abs(prefix[i]-nums[i]*(i+1))+abs(suffix[i+1]-nums[i]*(n-i-1));
           }else{
               res[i]=abs(prefix[i]-nums[i]*n);
           }
       } 
       return res;
    }
};