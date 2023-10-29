class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int total = minutesToTest/minutesToDie;
        return ceil(log2(buckets)/log2(total+1));
    }
};