class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int j = 0;
        for(int i = 0; i < n; i++){
            if(target[i] != '_'){
                while(j < n && (start[j] != target[i]) && start[j] == '_')++j;     
                if((j == n) || (start[j] != target[i]) ||((start[j] == 'L' && target[i] == 'L') && i > j) ||
                  ((start[j] == 'R' && target[i] == 'R') && i < j))return 0;
                ++j;
            }
        }
        while(j < n && start[j] == '_')++j;
        return j == n;
    }
};