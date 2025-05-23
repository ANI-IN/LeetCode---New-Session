class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans=mat;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
        
        while(!q.empty())
        {
            int dist=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            ans[r][c]=dist;
            
            for(int i=0;i<4;i++)
            {
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    q.push({dist+1,{nr,nc}});
                }
            }
        }
        return ans;
    }
};