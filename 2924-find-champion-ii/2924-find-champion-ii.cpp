class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> adj[n] , inD(n,0);
        for(auto & it : edges){
            adj[it[0]].push_back(it[1]);
            inD[it[1]]++;
        }
        int inDcount = 0;
        int winner = 0;
        for(int i = 0; i < n; i++){
            if(!inD[i]){
                ++inDcount;
                winner = i;
            }
        }
        return inDcount == 1 ? winner : -1;
    }
};