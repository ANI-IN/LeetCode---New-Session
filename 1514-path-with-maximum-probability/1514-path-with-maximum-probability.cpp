class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>> adj[n];
        int m=edges.size();
        
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succProb[i];
            
            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }
        
        
        vector<double> distance(n,0.0);
        
        priority_queue<pair<double,int>> q;
        q.push({1.0,start_node});
       
        distance[start_node]=1.0;
        
        while(!q.empty())
        {
            int node=q.top().second;
            double probability=q.top().first;
            q.pop();
            
            for(auto it : adj[node])
            {
                int v=it.first;
                double p=it.second;
                
                if(distance[v] < p * probability)
                {
                    distance[v]=p*probability;
                    q.push({distance[v],v});
                }
            }
        }

            return distance[end_node];
    }
};