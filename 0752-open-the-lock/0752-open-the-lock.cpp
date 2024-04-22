class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000")return 0;
        unordered_set<string> dds(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> bfs;
        string init = "0000";
        if (dds.find(init) != dds.end()) return -1;
        visited.insert("0000");
        bfs.push("0000");
        int res = 0;
        while (!bfs.empty()) {
            int sz = bfs.size();
            for (int i = 0; i < sz; i++) {
                string t = bfs.front(); bfs.pop();
                vector<string> nbrs = move(nbrStrs(t));
                for (auto s : nbrs) {
                    if (s == target) return ++res;
                    if (visited.find(s) != visited.end()) continue;
                    if (dds.find(s) == dds.end()) {
                        bfs.push(s);
                        visited.insert(s);
                    }
                }
            }
            ++res;
        }
        return -1;
    }
    
    
    vector<string> nbrStrs(string key) {
        vector<string> res;
        for (int i = 0 ; i < 4; i++) {
            string tmp = key;
            tmp[i] = (key[i] - '0' + 1) % 10 + '0';
            res.push_back(tmp);
            tmp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(tmp);
         }
        return res;
    }
};