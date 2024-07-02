class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        for(auto &it : nums1)freq[it]++;
        vector<int>result;
        for(auto &it : nums2){
            if(freq.count(it)){
              result.push_back(it);
              --freq[it];
              if(freq[it]==0)freq.erase(it);
            }
        }
        return result;
    }
};