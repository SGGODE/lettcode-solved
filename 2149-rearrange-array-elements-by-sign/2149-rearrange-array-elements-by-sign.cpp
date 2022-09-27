class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
     int n=nums.size();  
      vector<int>v;
      vector<int>pos,neg;
       for(int i=0;i<n;i++){
        if(nums[i]>=0){
            pos.push_back(nums[i]);
        }else{
            neg.push_back(nums[i]);
        }
     }
     int j=0;
      for(int i=0;i<n/2;i++){
          v.push_back(pos[j]);
          v.push_back(neg[j]);
          j++;
      }
        return v;
    }
};