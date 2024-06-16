class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long count = 0;
        unordered_map<int,long long>sum;
        for(auto&it:hours){
            if(sum.count((24-(it%24)))){
                count += sum[(24-(it%24))];
            }else if(it%24==0){
                count+=sum[0];
            }
            sum[it%24]++;
        }
        return count;
    }
};