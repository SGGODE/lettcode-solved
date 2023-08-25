class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>cumxor;
        int xors=0;
        for(int i=0;i<arr.size();i++){
            xors^=arr[i];
            cumxor.push_back(xors);
        }
        // for(auto&it:cumxor)cout<<it<<" ";
        // cout<<endl;
        // for(int i=1;i<cumxor.size();i++){
        //     cout<<(cumxor[i]^cumxor[i-1])<<" ";
        // }cout<<endl;
        vector<int>res;
        for(int i=0;i<queries.size();i++){
            int prev=cumxor[queries[i][0]];int add=cumxor[queries[i][1]];
            if(queries[i][0]==queries[i][1]){
                res.push_back(arr[queries[i][0]]);
                continue;
            }
            //if(queries[i][0]>1)prev=cumxor[queries[i][0]]^cumxor[queries[i][0]-1];
            if(queries[i][0]>=1)add=cumxor[queries[i][1]]^cumxor[queries[i][0]-1];
            //cout<<prev<<" "<<add<<endl;
            res.push_back(add);
        }
        return res;
    }
};