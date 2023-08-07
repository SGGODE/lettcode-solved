class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int s = 0;
        int e = (m*n)-1;
        while(s<=e){
            int mid = (s+e)/2;
            int ele = matrix[mid/m][mid%m];
            if(ele==target)return 1;
            if(ele<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return 0;
    }
};