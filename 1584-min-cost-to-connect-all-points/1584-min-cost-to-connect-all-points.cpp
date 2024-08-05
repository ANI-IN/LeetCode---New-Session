class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>> adj[n];
        int sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            int xi=points[i][0];
            int yi=points[i][1];
            
            for(int j=i+1;j<n;j++)
            {
                int xj=points[j][0];
                int yj=points[j][1];
                int distance=abs(xi-xj) + abs(yi-yj) ;
                adj[i].push_back({j,distance});
                adj[j].push_back({i, distance});
            }
        }
        
        q.push({0,0});
        
        while(!q.empty())
        {
            int node=q.top().second;
            int distance=q.top().first;
            q.pop();
            
            if(vis[node]==1)
                continue;
            
            vis[node]=1;
            sum+=distance;
            
            for(auto it : adj[node])
            {
                int v=it.first;
                int wt=it.second;
                
                if(!vis[v])
                {
                    q.push({wt,v});
                }
            }
        }
        return sum; 
        
    }
};