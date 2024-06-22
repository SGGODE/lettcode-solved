class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int , int>odd_count;
        int total = 0;
        int count = 0;
        odd_count[count]++;
        for(auto& it : nums){
            if(it%2)++count;
            if(odd_count.count(count-k))total += odd_count[count-k];
            odd_count[count]++;
        }
        return total;
    }
};