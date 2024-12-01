/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    int dfs(vector<int>adj[] , vector<int>importances , int id){
        //if(adj[id].empty())return importances[id];
        int ans = 0;
        for(auto & it : adj[id]){
            ans += (importances[it] + dfs(adj , importances , it));
        }
        return ans;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        n += 1;
        vector<int>adj[2001];
        vector<int>importances(2001 , 0);
        for(auto & it : employees){
            int idz = it->id;
            int imp = it->importance;
           // cout<<idz<<" "<<imp<<endl;
            importances[idz] = imp;
           // cout<<idz<<" "<<imp<<endl;
            vector<int>childs = it->subordinates;
            for(auto vt : childs){
                adj[idz].push_back(vt);
            }
        }
        return importances[id] + dfs(adj , importances , id);
    }
};