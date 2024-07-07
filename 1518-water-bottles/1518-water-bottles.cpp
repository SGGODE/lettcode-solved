class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        while(empty>=numExchange){
            int cnt = 0;
            while(empty>=numExchange){
                ++cnt;
                empty-=numExchange;
            }
            numBottles+=cnt;
            empty+=cnt;
        }
        return numBottles;
    }
};