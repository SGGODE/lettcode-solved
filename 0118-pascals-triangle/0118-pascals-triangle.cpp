class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i=1;i<=numRows;i++){
            if(i==1)res.push_back({1});
            else if(i==2)res.push_back({1,1});
            else{
                vector<int>temp;
                temp.push_back(1);
                vector<int>t=res.back();
                // for(auto&it:t)cout<<it<<" ";
                // cout<<endl;
                for(int j=1;j<i-1;j++){
                    temp.push_back(t[j-1]+t[j]);
                }
                //for(auto&it:temp)cout<<it<<" ";
               // cout<<endl;
                temp.push_back(1);
                res.push_back(temp);
            }
        }
        return res;
    }
};