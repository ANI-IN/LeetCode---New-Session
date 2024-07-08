class Solution {
    void dfs(int node,vector<int>&vis, vector<vector<int>>& arr)
    {
        vis[node]=1;
        
        for(int j=0;j<arr[node].size();j++)
        {
            if(arr[node][j]==1 && !vis[j])
                dfs(j,vis,arr);
                
        }
    }
public:
    int findCircleNum(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,arr);
                ans++;
            }
        }
        return ans;
    }
};