class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Lambda function to check if the grid is disconnected
        auto isDisconnected = [&]() {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            int landCount = 0;
            int componentCount = 0;
            
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1 && !visited[i][j]) {
                        ++componentCount;
                        if (componentCount > 1) return true; // more than one component, disconnected
                        // BFS to count the connected component
                        queue<pair<int, int>> q;
                        q.push({i, j});
                        visited[i][j] = true;
                        
                        while (!q.empty()) {
                            auto [x, y] = q.front(); q.pop();
                            ++landCount;
                            
                            int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
                            for (auto& d : dirs) {
                                int nx = x + d[0], ny = y + d[1];
                                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]) {
                                    visited[nx][ny] = true;
                                    q.push({nx, ny});
                                }
                            }
                        }
                    }
                }
            }
            return landCount == 0 || componentCount != 1;
        };
        
        // Check if the grid is already disconnected
        if (isDisconnected()) return 0;

        // Check if it can be disconnected by changing one cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (isDisconnected()) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        // If the grid cannot be disconnected by one change, return 2
        return 2;
    }
};