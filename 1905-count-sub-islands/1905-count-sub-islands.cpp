class Solution {
    int solve(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>> &vis) {
        queue<pair<int, int>> q; // Queue for BFS traversal
        bool ans = true; // Flag to determine if the current sub-island is valid
        int n = grid1.size(); // Number of rows
        int m = grid2[0].size(); // Number of columns
        
        // Directions for moving in 4 cardinal directions (right, down, left, up)
        int dx[4] = {0, +1, 0, -1};
        int dy[4] = {+1, 0, -1, 0};
        
        // Start BFS from the given cell
        q.push({i, j});
        
        while (!q.empty()) {
            int r = q.front().first; // Current row
            int c = q.front().second; // Current column
            q.pop();
            
            // If grid1 does not have land at the current cell, this is not a valid sub-island
            if (grid1[r][c] != 1)
                ans = false;
            
            // Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i]; // New row
                int nc = c + dy[i]; // New column
                
                // Check bounds, whether grid2 has land, and if the cell is not visited
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid2[nr][nc] == 1 && !vis[nr][nc]) {
                    vis[nr][nc] = 1; // Mark the cell as visited
                    q.push({nr, nc}); // Add the cell to the queue
                }
            }
        }
        
        // Return 1 if the sub-island is valid, otherwise return 0
        return ans ? 1 : 0;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size(); // Number of rows in grid2
        int m = grid2[0].size(); // Number of columns in grid2
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited array to track cells in grid2
        int ans = 0; // Count of sub-islands
        
        // Traverse each cell in grid2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is land in grid2 and not visited, start a BFS
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    int c = solve(i, j, grid1, grid2, vis); // Check if it's a valid sub-island
                    ans += c; // Increment count if valid
                }
            }
        }
        return ans; // Return the total count of sub-islands
    }
};