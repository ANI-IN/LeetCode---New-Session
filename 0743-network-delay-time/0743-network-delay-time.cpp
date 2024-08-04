class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        vector<int> dist(n+1,1e9);
        for(auto it : times)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        dist[k]=0;
        
        while(!q.empty())
        {
            int node=q.top().second;
            int w=q.top().first;
            q.pop();
            
            for(auto it : adj[node])
            {
                int v=it.first;
                int wt=it.second;
                
                if(w+wt<dist[v])
                {
                    dist[v]=w+wt;
                    q.push({dist[v],v});
                }
            }
        }
        
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)
                return -1;
            else 
                maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};