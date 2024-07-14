class Solution {
    bool dfs(int node, vector<int>&vis,vector<int>&path,vector<int>&safe,vector<int> adj[])
    {
        vis[node]=1;
        path[node]=1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,path,safe,adj)==true)
                    return true;
            }
            else if(path[it]==1)
            {
                safe[it]=0;
                return true;
            }
        }
        safe[node]=1;
        path[node]=0;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n=graph.size();
            vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(auto it : graph[i])
            {
                adj[i].push_back(it);
            }
        }
        
        vector<int> vis(n+1,0);
        vector<int> path(n+1,0);
        vector<int> safe(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,path,safe,adj);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(safe[i]==1)
                ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};