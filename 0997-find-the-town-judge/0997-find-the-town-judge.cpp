class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,set<int>>mp;
        for(auto&it:trust){
            mp[it[0]].insert(it[1]);
        }
        for(int i=1;i<=n;i++){
            if(!mp.count(i)){
                bool flag = 1;
                for(int j=1;j<=n;j++){
                    if(i!=j&&!mp[j].count(i)){
                        flag=0;
                        break;
                    }
                }
                if(flag)return i;
            }
        }
        return -1;
    }
};