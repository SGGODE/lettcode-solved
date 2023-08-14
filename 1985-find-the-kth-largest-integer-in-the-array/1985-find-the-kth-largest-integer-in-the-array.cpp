class Solution {
public:
static bool compare(string s1,string s2){
    if(s1.size()==s2.size()){
        return s1>s2;
    }
    return s1.size() > s2.size();
}
//public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),compare);
       // for(auto&it:nums)cout<<it<<" ";
      //  cout<<endl;
        return nums[k-1];
    }
};