class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        //rows ,cols , counts.
        int n = matrix.size(), m = matrix[0].size(), count = 1;
        for(int i = 0; i < n; i++){
            int cnt = 1;
            for(int j = i+1; j < n; j++){
                // if x == y
                if(matrix[i] == matrix[j])++cnt;
                else{
                    vector<int>temp(matrix[i]) , tempx(matrix[j]);
                   // cout<<i<<" "<<j<<endl;
                    for(int k = 0; k < m; k++){
                        if(temp[k])temp[k] = 0;
                        else temp[k] = 1;
                        //cout<<temp[k]<<" ";
                    }//cout<<endl;
                    //reverse(temp.begin() , temp.end());
                    if(temp == tempx)++cnt;
                }
            }
            count = max(count , cnt);
        }
        return count;
    }
};