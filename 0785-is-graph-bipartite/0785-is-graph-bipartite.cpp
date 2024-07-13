class Solution {
    bool solve(int node, int color,vector<int>&col,vector<int> adj[])
    {
        queue<int> q;
        q.push(node);
        col[node]=color;
        
        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            
            for(auto it : adj[n])
            {
                if(col[it]==-1)
                {
                    col[it]=1-col[n];
                    q.push(it);
                }
                else if(col[it]==col[n])
                    return false;
            }
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
                if(solve(i,0,col,adj)==false)
                    return false;
            }
        }
        return true;
    }
};