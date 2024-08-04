class Solution {
    void dfs(int node,vector<int> adj[],vector<int>&vis,int &e)
    {
        vis[node]=1;
        e++;
        
        for(auto it : adj[node])
            if(!vis[it])
                dfs(it,adj,vis,e);
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n,0);
        long long total=n;
        long long ans=0;
        
        for(int i=0;i<n;i++)
        {   
            int element=0;
            if(!vis[i])
            {
                dfs(i,adj,vis,element);
            }
            ans=ans+(element)*(total-element);
            total=total-element;
        }
        
        return ans;
    }
};