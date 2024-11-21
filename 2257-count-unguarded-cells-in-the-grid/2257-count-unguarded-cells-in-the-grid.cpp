// class Solution {
// public:
//     int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
//         map<pair<int,int>,int>mp;
//         unordered_map<int,int>rows,cols;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 rows
//             }
//         }
//         for(auto&it : walls){
//          // for(auto&vt : it){
//               mp[{it[0],it[1]}]++;
//               vis[it[0]][it[1]] = 1;
//          // }
//         }
//         queue<pair<int,int>>pq;
//         for(auto&it:guards){
//         //    for(auto&vt:it){
//                 pq.push({it[0],it[1]});
//         //    }
//         }
//         while(!pq.empty()){
//             int row = pq.front().first;
//             int col = pq.front().second;
//             pq.pop();
//             //vis[row][col] = 1;
//             //rows flood fill algo.
//             for(int i = row; i < n; i++){
//                 if(!mp.count({i,col}))vis[i][col] = 1;
//                 else break;
//             }
//             for(int i = row; i >= 0; i--){
//                 if(!mp.count({i,col}))vis[i][col] = 1;
//                 else break;
//             }
//             //cols flood fill algo.
//             for(int i = col; i < m; i++){
//                 if(!mp.count({row,i}))vis[row][i] = 1;
//                 else break;
//             }
//             for(int i = col; i >= 0; i--){
//                 if(!mp.count({row,i}))vis[row][i] = 1;
//                 else break;
//             }
//         }
//         int count = 0;
//         for(auto&it : vis){
//             for(auto vt : it){
//                 if(!vt){++count;}
//                // else cout<<" . ";
//             }//cout<<endl;
//         }
//         return count;
//     }
// };
class Solution {
public:
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    void markguarded(int row, int col, vector<vector<int>>& grid) {
        // Traverse upwards
        for (int r = row - 1; r >= 0; r--) {
            if (grid[r][col] == WALL || grid[r][col] == GUARD) break;
            grid[r][col] = GUARDED;
        }
        // Traverse downwards
        for (int r = row + 1; r < grid.size(); r++) {
            if (grid[r][col] == WALL || grid[r][col] == GUARD) break;
            grid[r][col] = GUARDED;
        }
        // Traverse leftwards
        for (int c = col - 1; c >= 0; c--) {
            if (grid[row][c] == WALL || grid[row][c] == GUARD) break;
            grid[row][c] = GUARDED;
        }
        // Traverse rightwards
        for (int c = col + 1; c < grid[row].size(); c++) {
            if (grid[row][c] == WALL || grid[row][c] == GUARD) break;
            grid[row][c] = GUARDED;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

        // Mark guards' positions
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        // Mark walls' positions
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        // Mark cells as guarded by traversing from each guard
        for (const auto& guard : guards) {
            markguarded(guard[0], guard[1], grid);
        }

        // Count unguarded cells
        int count = 0;
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                if (cell == UNGUARDED) count++;
            }
        }
        return count;
    }
};