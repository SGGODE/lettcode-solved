class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        result.push_back({intervals[0][0],intervals[0][1]});
        int j = 0;
        for(int i=1;i<intervals.size();i++){
            int start = result[j][0];
            int end = result[j][1];
            if(intervals[i][0]<=end){
                result[j][0]=min(result[j][0],intervals[i][0]);
                result[j][1]=max(result[j][1],intervals[i][1]);
            }else{
                result.push_back({intervals[i][0],intervals[i][1]});
                j++;
            }
        }
        return result;
    }
};