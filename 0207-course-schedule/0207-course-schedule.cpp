class Solution {
    bool dfs(int node,vector<int>&vis,vector<int> adj[],vector<int>&path)
    {
        vis[node]=1;
        path[node]=1;

        for(auto it : adj[node])
        {
            if(vis[it]==0)
            {
                if(dfs(it,vis,adj,path))
                    return true;
            }
            else if(vis[it]==1 && path[it]==1)
            {
                return true;
            }
        }
        path[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& mat) {
        
        int n=numCourses;
        vector<int> adj[n];
        vector<int> vis(n,0);
        vector<int> path(n,0);
        int count=0;
        for(auto it : mat)
        {
            int u=it[1];
            int v=it[0];
            
            adj[u].push_back(v);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,adj,path))
                    return false;
            }
        }
        return true;
        
        
    }
};