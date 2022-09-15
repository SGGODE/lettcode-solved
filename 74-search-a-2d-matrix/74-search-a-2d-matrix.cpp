class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int s=0;
        int e=(n*m)-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            int element=matrix[mid/m][mid%m];
            if(element==target)
                return 1;
            else if(element<target)
               s=mid+1;
            else
                e=mid-1;
            mid=s+(e-s)/2;
      }
        return 0;
    }
};