class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int dr[4] = {0,0,+1,-1};
        int dc[4] = {+1,-1,0,0};
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});     //{cost,{i,j}}
        
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int cost = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(cost > dist[r][c]) 
                continue;

            if(r==n-1 && c==m-1)
            {
                 return cost; 
            }

            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int newCost = cost + ((i + 1 == grid[r][c]) ? 0 : 1);

                     if(newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, {nr, nc}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
