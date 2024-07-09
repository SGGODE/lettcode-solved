class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
         int n = customers.size();
         int wait = 0;
         vector<double>wTime;
        double result = 0;
         for(int i = 0 ; i < n ; i++){
             if(wait == 0){
                 wait = (double)(customers[i][0] + customers[i][1]);
                 result += (wait - customers[i][0]);
             }else{
                 if(customers[i][0] > wait){
                     wait = (double)(customers[i][0] + customers[i][1]);
                     result += (wait - customers[i][0]);
                 }else{
                     int start = max(customers[i][0],wait);
                 int w = start + customers[i][1];
                 result += (w-customers[i][0]);

                 wait += customers[i][1];
                 }
             }
         }
        return result/n;
    }
};