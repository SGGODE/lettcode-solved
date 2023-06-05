class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // int n=corrdinates.size();
        // for(int i=1;i<n;i++){
        //     if(abs(corrdinates[i][0]-corrdinates[i-1][0])==abs(corrdinates[i][1]-corrdinates[i-1][1]))continue;
        //     else return false;
        // }
        // return true;
           int cz = coordinates.size();
        if (cz == 1) return false;  // One point only, not a straight line
        if (cz == 2) return true;  // Two points only, always a straight line
        
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int dx = coordinates[1][0] - x0, dy = coordinates[1][1] - y0;
        
        for (int i = 1; i < cz; i++) {   // Checking two point formula for each point with the first point
            int x = coordinates[i][0], y = coordinates[i][1];
            if (dx * (y - y0) != dy * (x - x0))  // Two point formula of line, if (x2-x1)*(y1-y0) = (x1-x0)(y2-y1), then a straight line, otherwisnot
			    return false;
        }
        return true;
    }
};