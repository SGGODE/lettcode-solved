// class Solution {
// private:
//     int sub(vector<vector<int>>&events,int index,int last,int sum,int k){
//         if(k==0||index==events.size()){
//             return sum;
//         }
//         int notpick = sub(events,index+1,last,sum,k);
//         int pick = 0;
//         if(last==-1||last<events[index][0]){
//             pick = sub(events,index+1,events[index][1],sum+events[index][2],k-1);
//         }
//         return max(pick,notpick);
//     }
// public:
//     int maxValue(vector<vector<int>>& events, int k) {
//         sort(events.begin(),events.end());
//         return sub(events,0,-1,0,k);
//     }
// };
class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<vector<int>>&events,int index,int k){
        if(k==0||index==events.size()){
            return 0;
        }
        if(dp[index][k]!=-1)return dp[index][k];
        int i=index;
        for(i=index+1;i<events.size();i++){
            if(events[i][0]>events[index][1])break;
        }
        return dp[index][k]=max(events[index][2]+sub(dp,events,i,k-1),sub(dp,events,index+1,k));
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return sub(dp,events,0,k);
    }
};