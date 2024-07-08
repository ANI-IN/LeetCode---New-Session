class Solution {
    void dfs(int node,vector<int> adj[],vector<int>&vis)
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
                dfs(it,adj,vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<int> adj[n+1];
        vector<int> vis(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
        
    }
};