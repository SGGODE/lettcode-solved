// class Solution {
// private:
//     bool check(int index,vector<int>& gas, vector<int>& cost){
//         bool ans=1;
//         int curr_gas=gas[index];
//         int curr_cost=0;
//         if(index==gas.size()-1){
//             curr_gas-=cost[gas.size()-1];
//            // continue;
//         }else if(index==0){
//             curr_gas-=cost[0];
//            for(int i=index+1;i<gas.size();i++){
//             curr_gas+=gas[i];
//             curr_cost=cost[i];
//             if(curr_gas-curr_cost>=0){
//                 curr_gas-=curr_cost;
//                 //curr_gas+=gas[index]
//             }else return 0;
//         } 
//         }
//         else{
//             curr_gas-=cost[index];
//         for(int i=index+1;i<gas.size();i++){
//             curr_gas+=gas[i];
//             curr_cost=cost[i];
//             if(curr_gas-curr_cost>=0){
//                 curr_gas-=curr_cost;
//                 //curr_gas+=gas[index]
//             }else return 0;
//         }}
//         for(int i=0;i<=index;i++){
//             curr_gas+=gas[i];
//             curr_cost=cost[i];
//             if(curr_gas-curr_cost>=0){
//                 curr_gas-=curr_cost;
//                 //curr_gas+=gas[index]
//             }else return 0;
//         }
//         cout<<curr_gas<<" "<<curr_cost<<endl;
//         return 1;
//     }
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         vector<int>possible;
//         for(int i=0;i<gas.size();i++){
//             if(gas[i]-cost[i]>=0){
//                 possible.push_back(i);
//             }
//         }
//         for(int i=0;i<possible.size();i++){
//             if(check(possible[i],gas,cost)){
//                 return possible[i];
//             }
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int sum=0;
        for(int i=0;i<gas.size();i++){
            sum+=gas[i]-cost[i];
        }
        if(sum<0)return -1;
        int curr_sum=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            curr_sum+=gas[i]-cost[i];
            if(curr_sum<0){
                start=i+1;
                curr_sum=0;
            }
        }
        return start;
    }
};