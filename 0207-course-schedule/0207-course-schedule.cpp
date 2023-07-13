class Solution {
public:
    bool canFinish(int n, vector<vector<int>>&nums) {
        vector<int>adj[n+1];
        for(int i=0;i<nums.size();i++){
            adj[nums[i][1]].push_back(nums[i][0]);
        }
        vector<int>income(n,0);
        for(int i=0;i<n;i++){
            for(auto&it:adj[i]){
                income[it]++;
            }
        }
        queue<int>pq;
        for(int i=0;i<n;i++){
            if(income[i]==0)pq.push(i);
        }
        set<int>s;
        while(!pq.empty()){
            int node=pq.front();
            pq.pop();
            s.insert(node);
            for(auto&it:adj[node]){
                --income[it];
                if(income[it]==0)pq.push(it);
            }
        }
        return s.size()==n;
    }
};