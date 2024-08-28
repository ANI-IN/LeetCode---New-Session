class Solution {
    bool solve(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis)
    {
        queue<pair<int,int>> q;
        int n=grid1.size();
        int m=grid1[0].size();
        
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        
        vis[i][j]=1;
        q.push({i,j});
        
        bool island=true;
        
        if(grid1[i][j]!=1)
            island=false;
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            
            
            for(int k=0;k<4;k++)
            {
                int nr=r+delrow[k];
                int nc=c+delcol[k];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    if(grid2[nr][nc]==1 && !vis[nr][nc])
                    {
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                        
                        if(grid1[nr][nc]!=1)
                          island=false;  
                    }
                }
            }
        }
        
        return island;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid2[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1 && !vis[i][j])
                {
                 if(solve(i,j,grid1,grid2,vis))
                     ans++;
                }
            }
        }
        return ans;
    }
};