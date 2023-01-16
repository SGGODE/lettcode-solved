class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<int>v;
        int j=0;
        for(auto it:intervals){
            cout<<it[0]<<" "<<it[1]<<" ";
        }cout<<endl;
        for(int i=0;i<intervals.size();i++){
            if(i==0){
                v.push_back(intervals[i][0]);
                v.push_back(intervals[i][1]);
                j+=2;
            }else{
                if(intervals[i][0]>v[j-1]){
                   // cout<<v[i-1]<<endl;
                    v.push_back(intervals[i][0]);
                    v.push_back(intervals[i][1]);
                    j+=2;
                }else{
                    v[j-1]=max(intervals[i][1],v[j-1]);
                }
            }
        }
        vector<vector<int>>result;
        for(int i=0;i<v.size();i+=2){
            result.push_back({v[i],v[i+1]});
        }
        return result;
    }
};