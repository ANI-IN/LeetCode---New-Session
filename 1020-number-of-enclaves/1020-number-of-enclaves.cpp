class Solution {
    void dfs(int i, int j, vector<vector<int>>& board,vector<vector<int>> &vis)
    {
        vis[i][j]=1;
        board[i][j]=0;
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        
        int m=board.size();
        int n=board[0].size();
        
        for(int k=0;k<4;k++)
        {
            int nr=i+delRow[k];
            int nc=j+delCol[k];
            
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]==1)
            {
                dfs(nr,nc,board,vis);
            }
        }
        
        
    }
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && board[0][j]==1)
                dfs(0,j,board,vis);
            
            if(!vis[n-1][j] && board[n-1][j]==1)
                dfs(n-1,j,board,vis);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0]==1)
                dfs(i,0,board,vis);
            
            if(!vis[i][m-1] && board[i][m-1]==1)
                dfs(i,m-1,board,vis);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==1)
                    ans++;
            }
        }
        return ans;

    }
};