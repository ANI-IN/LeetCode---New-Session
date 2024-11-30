class Solution {
    int solve(int i, int j, vector<vector<int>>&grid1, vector<vector<int>>&grid2,vector<vector<int>> &vis)
    {
        queue<pair<int,int>>q;
        bool ans=true;
        int n=grid1.size();
        int m=grid2[0].size();
        
        int dx[4]={0,+1,0,-1};
        int dy[4]={+1,0,-1,0};
        
        q.push({i,j});
        
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            if(grid1[r][c]!=1)
                ans=false;
            
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid2[nr][nc]==1 && !vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        
        if(ans)
            return 1;
        else
            return 0;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1 && !vis[i][j])
                {
                    int c = solve(i,j,grid1,grid2,vis);
                    ans+=c;
                }
            }
        }
        return ans;
    }
};