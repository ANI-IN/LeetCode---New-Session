class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int total=0;
        int time=0;
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    total++;
                   
                }     
                if(grid[i][j]==2)
                        q.push({i,j});
            }
        }
        
        int dr[4]={-1,0,+1,0};
        int dc[4]={0,+1,0,-1};
        
        int c=0;
        while(!q.empty())
        {
            int size=q.size();
            c+=size;
            for(int j=0;j<size;j++)
            {
                int rr=q.front().first;
                int cc=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int r=rr+dr[i];
                int c=cc+dc[i];
                
                if(r<0 || c<0 || r>=n || c>=m || grid[r][c]!=1)
                    continue;
                
                grid[r][c]=2;
                q.push({r,c});
                }
                
            }
            if (!q.empty()) time++;
        }
        
        return total == c ? time : -1;
    }
};