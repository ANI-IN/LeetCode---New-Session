class Solution {
    void dfs(int node, vector<int>&vis, vector<vector<int>>& mat)
    {
        vis[node]=1;
        
        for(int i=0;i<mat[node].size();i++)
        {
            if(mat[node][i]==1 && vis[i]==0)
                dfs(i,vis,mat);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        
        vector<int> vis(n,0);
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                ans++;
                dfs(i,vis,mat);
            }
        }
        return ans;
        
    }
};