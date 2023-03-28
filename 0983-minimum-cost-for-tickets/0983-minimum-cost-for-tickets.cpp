class Solution {
private:
    int dfs(vector<int>&days,int index,vector<int>&costs,vector<int>&dp,int n,int currdays){
        if(index>=n){
           // if(currdays>=days[n-1]){
                return 0;
           // }//else{
               // return *min_element(costs.begin(),costs.end());
          //  }
        }
        if(dp[index]!=-1)return dp[index];
        
        int option1=costs[0]+dfs(days,index+1,costs,dp,n,currdays);
        int i;
        for(i=index;i<n&&days[i] < days[index]+7;i++);
            
        int option2=costs[1]+dfs(days,i,costs,dp,n,currdays);
        
        for(i=index;i<n&&days[i] < days[index]+30;i++);
            
        int option3=costs[2]+dfs(days,i,costs,dp,n,currdays);
        
        return dp[index]=min(option1,min(option2,option3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n,-1);
       return dfs(days,0,costs,dp,n,0);
        return dp[0];
    }
};