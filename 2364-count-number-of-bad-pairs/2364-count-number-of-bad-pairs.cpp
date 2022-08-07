class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long c=0;
       /* for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(i<j&& j-i!=nums[j]-nums[i])
                    c++;
            }
            j=i+1;
          while(j<n){
             if(i<j&& j-i!=nums[j++]-nums[i])
                    c++; 
          }
        }*/
        int n=nums.size();
        unordered_map<int,int> s;
      for(int i=0;i<n;i++){
          c+=i-s[nums[i]-i];
          s[nums[i]-i]++;
       }
        return c;
    }
};