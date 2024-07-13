class Solution {
    bool solve(int node, int color,vector<int>&col,vector<int> adj[])
    {
        col[node]=color;
        for(auto it : adj[node])
        {
            if(col[it]==-1)
            {
                if(solve(it,!color,col,adj)==false)
                    return false;
            }
            else if(col[it]==color)
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n+1];
        
        for(int i=0;i<n;i++)
        {
            for(auto it : graph[i])
            {
                adj[i].push_back(it);
                adj[it].push_back(i);
            }
        }
        
        vector<int> col(n+1,-1);
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(solve(i,1,col,adj)==false)
                    return false;
            }
        }
        return true;
    }
};