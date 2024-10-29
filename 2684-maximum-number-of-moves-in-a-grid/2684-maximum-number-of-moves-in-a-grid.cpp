class Solution {
    int solve(int i, int j, vector<vector<int>>&grid,vector<vector<int>>&dp )
    {
        if(j>=grid[0].size())
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int n = grid.size();
        int m = grid[0].size();
        int maxMoves = 0;  
        
       
        for (int ni = i - 1; ni <= i + 1; ni++) {
            if (ni >= 0 && ni < n && j + 1 < grid[0].size()  && grid[ni][j + 1] > grid[i][j]) {
                maxMoves = max(maxMoves, 1 + solve(ni, j + 1, grid, dp));
            }
        }
        
        return dp[i][j]=maxMoves;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int ans=0;
        for(int j=0;j<n;j++)
        {
            ans=max(ans,solve(j,0,grid,dp));
        }
        return ans;
    }
};