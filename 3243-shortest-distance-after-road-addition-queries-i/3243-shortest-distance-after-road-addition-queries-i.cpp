class Solution {
    void solve(int n, vector<int>adj[], vector<int>&ans)
    {
        vector<int> dist(n,1e9);
        dist[0]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> q;
        q.push({0,0});
        
        
        while(!q.empty())
        {
            int node=q.top().second;
            int wt= q.top().first;
            q.pop();
            
            if(node==n-1)
            {
                ans.push_back(wt);
                break;
            }
            
            for(auto it : adj[node])
            {
                int v = it;
                
                if(wt + 1 < dist[v])
                {
                    dist[v] = wt + 1;
                    q.push({dist[v],v});
                }
            }
        }
        
        return;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> adj[n];
        for(int i=0;i<n-1;i++)
        {
            adj[i].push_back(i+1);
        }
        vector<int> ans;
        
        for(int i=0;i<queries.size();i++)
        {
            int u=queries[i][0];
            int v=queries[i][1];
            
            adj[u].push_back(v);
            
            solve(n,adj,ans);
        }
        return ans;
    }
};