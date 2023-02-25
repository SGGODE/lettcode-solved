class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int max_diff=0;
       // for(int i=0;i<prices.size();i++){
       //     int m=*max_element(prices.begin()+i,prices.end());
       //     if(m>prices[i]){
       //         int x=m-prices[i];
       //         max_diff=max(max_diff,x);
       //     }
       // }
        int min_element=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<min_element){
                min_element=prices[i];
            }else{
                int x=prices[i]-min_element;
                max_diff=max(max_diff,x);
            }
        }
        return max_diff;
    }
};