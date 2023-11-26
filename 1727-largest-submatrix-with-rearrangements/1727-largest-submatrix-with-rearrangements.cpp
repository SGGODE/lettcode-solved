class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
       //  int mlen = 0;
       //  int m = matrix[0].size();
       //  int n = matrix.size();
       //  vector<vector<int>>res(n,vector<int>(m,0));
       //  for(int i=0;i<matrix.size();i++){
       //      for(int j=0;j<matrix[0].size();j++){
       //          if(i>0)res[i][j]=res[i-1][j];
       //          if(matrix[i][j]==1)res[i][j]+=1;
       //      }
       //      //res.push_back(cnt);
       //  }
       //  for(auto&it:res){
       //      for(auto vt:it)cout<<vt<<" ";
       //      cout<<endl;
       //  }
       //  //sort(res.begin(),res.end());
       //  for(int i=0;i<res.size();i++){
       //      int result = INT_MAX;
       //     // cout<<res[i]<<" ";
       //      sort(res[i].begin(),res[i].end());
       //      for(int j=res[0].size()-1;j>=0;j--){
       //          result = min(result,res[i][j]);
       //          mlen = max(mlen,(result*(m-j)));
       //      }   
       //  }
       // // cout<<endl;
       //  return mlen;
        int m=matrix.size(), n=matrix[0].size();
        int area=count(matrix[0].begin(), matrix[0].end(), 1);
        for(int i=1;  i<m; i++){
            #pragma unroll
            for(int j=0; j<n; j++){
                if (matrix[i][j]!=0)
                    matrix[i][j]+=matrix[i-1][j];
            }
            auto row=matrix[i];
            sort(row.begin(), row.end());
            #pragma unroll
            for(int i=0; i<n; i++)
                area=max(area, row[i]*(n-1-i+1));
        }
        return area;
    }
   
};