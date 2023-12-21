class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>Y_axis_points;
        for(auto&it:points){
            Y_axis_points.push_back(it[0]);
        }
        sort(Y_axis_points.begin(),Y_axis_points.end());
        int len = 0;
        for(int i=1;i<Y_axis_points.size();i++){
            int length = (Y_axis_points[i]-Y_axis_points[i-1]);
            len = max(len,length);
        }
        return len;
    }
};