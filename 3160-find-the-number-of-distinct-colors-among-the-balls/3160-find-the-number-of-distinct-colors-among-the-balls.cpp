class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       vector<int>result;
       unordered_map<int,int>col;
       unordered_map<int,int>val;
       for(auto&it:queries){
           if(val.count(it[0])){--col[val[it[0]]];
               if(col[val[it[0]]]==0)col.erase(val[it[0]]);
               ++col[it[1]];
               val[it[0]]=it[1];
           }else{
               ++col[it[1]];
               val[it[0]]=it[1];
           }
           result.push_back(col.size());
       }
      return result;
    }
};