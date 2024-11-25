// class Solution {
// private:
//     bool check(int r , int c){
//         return r >= 0 && c >= 0 && r < 2 && c < 3; 
//     }
//     bool checkBoard(vector<vector<int>>board){
//          return board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 &&
//                 board[1][0] == 4 && board[1][1] == 5;
//     }
//     int sub(vector<vector<int>>&board ,map<pair<int , int> , vector<pair<int , int>>>&moves , map<vector<vector<int>> , int>&dp , vector<vector<vector<bool>>>&vis , int r , int c){
//         if(checkBoard(board))return 0;
//        // if(vis[r][c][board[r][c]])return 1e9;
//         if(dp.count(board))return 1e9;
//         dp[board]++;
//         //vis[r][c][board[r][c]] = 1; 
//         int ans = 1e9;
//         int row[4] = {0 , 0 , 1 , -1};
//         int col[4] = {1 , -1 , 0 , 0};
//         for(auto & it : moves[{r , c}]){
//             //if(check(row + r , col[i] + c) ){
//                 int val = board[it.first][it.second];
//                 board[it.first][it.second] = 0;
//                 //vis[row[i] + r][col[i] + c] = 1;
//                 board[r][c] = val;
//                 ans = min(ans , 1 + sub(board , moves , dp , vis , it.first , it.second));
//                 board[it.first][it.second] = val;
//                 //vis[row[i] + r][col[i] + c] = 0;
//                 board[r][c] = 0;
//           //  }
//         }
//        // vis[r][c][board[r][c]] = 0;
//         //dp.erase(board);
//         return ans;
//     }
// public:
//     int slidingPuzzle(vector<vector<int>>& board) {
//         vector<vector<vector<bool>>>vis(2 , vector<vector<bool>>(3 ,vector<bool>(6,0)));
        
//         map<vector<vector<int>> , int> dp;
//         map<pair<int , int> , vector<pair<int , int>>> moves;
//         int row[4] = {0 , 0 , 1 , -1};
//         int col[4] = {1 , -1 , 0 , 0};
//         int r = 0 , c = 0;
//         for(int i = 0; i < 2; i++){
//             for(int j = 0; j < 3; j++){
//                 if(board[i][j] == 0)r = i , c = j;
//                 for(int k = 0; k < 4; k++){
//                     if(check(i + row[k] , j + col[k])){
//                         moves[{i , j}].push_back({i + row[k] , j + col[k]});
//                     }
//                 }
//             }
//         }
// //         queue<pair<int , int>> pq;
// //         pq.push({r, c});
// //         while(!pq.empty()){
// //             int size = pq.size();
// //             for(int i = 0; i < size; i++){
// //                 int rx = pq.front().first;
// //                 int cx = pq.front().second;
                
// //                 pq.pop();
// //                 for(int k = 0; k < 4; k++){
// //                     if(check(rx + row[k] , cx + col[k])){
// //                         swap()
// //                     }
// //                 }
// //             }
// //         }
//         int result = sub(board , moves , dp , vis , r , c);
//        return result == 1e9 ? -1 : result;
//     }
// };
class Solution {
private:
    // Direction map for zero's possible moves in a flattened 1D array (2x3
    // board)
    vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5},
                                      {0, 4}, {3, 5, 1}, {4, 2}};

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Convert the 2D board into a string representation to use as state
        string startState;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                startState += to_string(board[i][j]);
            }
        }

        // Map to store the minimum moves for each visited state
        unordered_map<string, int> visited;

        // Start DFS traversal from initial board state
        dfs(startState, visited, startState.find('0'), 0);

        // Return the minimum moves required to reach the target state, or -1 if
        // unreachable
        return visited.count("123450") ? visited["123450"] : -1;
    }

private:
    void dfs(string state, unordered_map<string, int>& visited, int zeroPos,
             int moves) {
        // Skip if this state has been visited with fewer or equal moves
        if (visited.count(state) && visited[state] <= moves) {
            return;
        }
        visited[state] = moves;

        // Try moving zero to each possible adjacent position
        for (int nextPos : directions[zeroPos]) {
            swap(state[zeroPos], state[nextPos]);  // Swap to generate new state
            dfs(state, visited, nextPos,
                moves + 1);  // Recursive DFS with updated state and move count
            swap(state[zeroPos],
                 state[nextPos]);  // Swap back to restore original state
        }
    }
};