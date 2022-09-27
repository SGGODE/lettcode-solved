class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>v;
        int n=matrix.size();
        int m=matrix[0].size();
        int total=n*m;
        int rs=0,cs=0;
        int re=n-1,ce=m-1;
        int count=0;
        while(count<total){
            for(int i=cs;i<=ce&&count<total;i++){
                v.push_back(matrix[rs][i]);
                count++;
            }
            rs++;
            for(int i=rs;i<=re&&count<total;i++){
                v.push_back(matrix[i][ce]);
               count++; 
            }
            ce--;
            for(int i=ce;i>=cs&&count<total;i--){
                v.push_back(matrix[re][i]);
                count++;
            }
            re--;
            for(int i=re;i>=rs&&count<total;i--){
                v.push_back(matrix[i][cs]);
                count++;
            }
            cs++;
        }
        return v;
    }
};