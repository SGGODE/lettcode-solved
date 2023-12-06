class Solution {
public:
    int totalMoney(int n) {
        int curr_money = 1;
        int lastmonday = 1;
        int sum = 1;
        int days = 1;
        --n;
        while(n!=0){
            ++days;//update day.
            ++curr_money;//update cost of day.
            --n;//reduce the no of days remain.
            if(days%8==0){ //if one cycle is done.
                curr_money = lastmonday+1; //update the money form last monday.
                lastmonday = curr_money; //update this monday as last monday for last.
                days = 1;
            }
            //add the current cost of the day.
            sum += curr_money;
        }
        return sum;
    }
};