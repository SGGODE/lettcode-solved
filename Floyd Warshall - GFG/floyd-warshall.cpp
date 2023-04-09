//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    int m=matrix[0].size();
	    vector<vector<int>>res(n,vector<int>(m,1e9));
	    for(int i=0;i<n;i++){
	       for(int j=0;j<m;j++){
	            if(i==j){
	               res[i][j]=0;
	               continue;
	           }
	           if(matrix[i][j]==-1){
	               res[i][j]=1e9;
	           }else{
	               res[i][j]=matrix[i][j];
	           }
	       }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            for(int k=0;k<n;k++){
	                res[j][k]=min(res[j][k],res[j][i]+res[i][k]);
	            }
	        }
	    }
	    matrix=res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends