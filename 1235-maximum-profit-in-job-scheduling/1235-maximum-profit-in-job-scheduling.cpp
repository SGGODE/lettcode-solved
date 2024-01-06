
class Solution {
private:
    int sub(vector<vector<int>>&xp,vector<int>&dp,int index,int last){
        //base case : index reach the last job + 1 
        //i.e no more remain job out there return 0; 
        if(index==xp.size())return 0;
        //if this index as choose before.
        if(dp[index]!=-1)return dp[index];
        //to store this state (index) maximum profit.
        int ans = 0;
        //just skip this index may try (index+1,last) job as maximum.
        ans = sub(xp,dp,index+1,last);
        vector<int>::iterator it;
        //if possible we can make this as starting job if last == -1
        //if not then weather the previous job that we choose
        //is not overlapping with one then do,
        if(last==-1||xp[last][1]<=xp[index][0]){
           //we are doing binary search i.e lower bound to get a job that that has start time
           //equal to end time of current job or just greater.
           auto lowerBoundIt = std::lower_bound(xp.begin()+index, xp.end(), std::vector<int>{xp[index][1]},
                        [](const std::vector<int>& a, const std::vector<int>& b) {
                            return a[0] < b[0];
                        });
            //get index of the next job which has equal or just greater start time.
            int lowerBoundIndex = std::distance(xp.begin(), lowerBoundIt);
            //if in array bound pass it as next index i.e index+1 (in linear search way) but
            //over here we just pass it way with lower_bound to minimize time complexity.
            if(lowerBoundIndex<xp.size())ans = max(ans,xp[index][2]+sub(xp,dp,lowerBoundIndex,index));
            else ans = max(ans,xp[index][2]);//if there is no job who have start time less than endtime of current job.
        }
        //just more the possible maximum result.
        return dp[index]=ans;        
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        //number of jobs.
        int n = profit.size();
        //to store all jobs with start , end and profit.
        vector<vector<int>>xp;
        //dp to memo.
        vector<int>dp(n,-1);
        //just push all jobs.
        for(int i=0;i<n;i++){
            xp.push_back({startTime[i],endTime[i],profit[i]});
        }
        //sort the jobs with respect to start time.
        sort(xp.begin(),xp.end());
        //go up and return the best. (maximum profit).
        return sub(xp,dp,0,-1);
    }
 };