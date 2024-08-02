class Solution {
    bool dfs(int node,vector<int> adj[],vector<int>&vis,stack<int>&st,vector<int>&path)
    {
        vis[node]=1;
        path[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,st,path)==true)
                    return true;
            }
            else if(path[it]==1)
                return true;
        }
        path[node]=0;
        st.push(node);
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<int> adj[n];
        for(auto it : arr)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> path(n,0);
        stack<int> st;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                if(dfs(i,adj,vis,st,path)==true)
                    return ans;
        }
        
    
            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
            return ans;
        
    }
};