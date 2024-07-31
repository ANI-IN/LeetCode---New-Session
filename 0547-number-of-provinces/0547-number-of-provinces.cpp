class Solution {
    void dfs(int node, vector<int>&vis, vector<int>adj[])
    {
        vis[node]=1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<int> adj[n+1];
        vector<int> vis(n,0);
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
        
    }
};