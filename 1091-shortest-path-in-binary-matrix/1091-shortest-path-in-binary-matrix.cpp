class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)
            return -1;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({1,{0,0}});
        dist[0][0]=1;
        
        int delrow[]={-1,-1,0,+1,+1,+1,0,-1};
        int delcol[]={0,+1,+1,+1,0,-1,-1,-1};
        
        while(!q.empty())
        {
            auto t=q.top();
            q.pop();
            
            int d=t.first;
            int r=t.second.first;
            int c=t.second.second;
            
            if(r==n-1 && c==n-1)
                return d;
            
            for(int i=0;i<8;i++)
            {
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && 1+d < dist[nr][nc])
                {
                    dist[nr][nc]=1+d;
                    q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        return -1;
        
    }
};