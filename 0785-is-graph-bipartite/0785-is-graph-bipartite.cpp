class Solution {
    bool dfs(int node, int col, vector<int>adj[],vector<int>&color)
    {
        color[node]=col;
        
        for(auto it : adj[node])
        {
            if(color[it]==-1)
            {
                if(dfs(it,!col,adj,color)==false)
                    return false;
            }
            else if(color[it]==col)
            {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            for(auto it : graph[i])
            {
                adj[i].push_back(it);
                
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,1,adj,color)==false)
                    return false;
            }
        }
        return true;
        
    }
};