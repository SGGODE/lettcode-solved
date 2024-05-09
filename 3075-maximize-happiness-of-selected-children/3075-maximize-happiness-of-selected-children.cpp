class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int t = k;
        int n = happiness.size();
        long long sum = 0;
        for(int i=n-1;i>=0&&k>0;i--){
            sum+=((happiness[i]-(t-k))<=0?0:((happiness[i]-(t-k))));
            --k;
        }
        return sum;
    }
};