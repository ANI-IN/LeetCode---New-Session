class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int dx[4] = {0,+1,0,-1};
        int dy[4] = {+1,0,-1,0};
        
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        
        dist[0][0]=grid[0][0];
        
        pq.push({dist[0][0],{0,0}});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int obstacle = it.first;
            int x=it.second.first;
            int y=it.second.second;
            
            if(x==n-1 && y==m-1)
                return obstacle;
            
            for(int i=0;i<4;i++)
            {
                int nr = x + dx[i];
                int ny = y + dy[i];
                
                if(nr >=0 && nr<n && ny>=0 && ny<m)
                {
                    int newObstacle = obstacle + grid[nr][ny];
                    if(newObstacle < dist[nr][ny])
                    {
                        dist[nr][ny] = newObstacle;
                        pq.push({newObstacle,{nr,ny}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};