class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        
        while(!q.empty())
        {
            int d=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                
     
                if(nr>=0 && nr<n && nc>=0 && nc<m )
                {   
                    int ef = abs(arr[r][c] - arr[nr][nc]);
                    int effort=max(ef,d);
                    if (effort < dist[nr][nc]) {
                        dist[nr][nc] = effort;
                        q.push({effort, {nr, nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};