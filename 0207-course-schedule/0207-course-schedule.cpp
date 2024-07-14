class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& g) {
        vector<int> adj[n];
        
        for(auto it : g)
        {
            int v=it[0];
            int u=it[1];
            adj[u].push_back(v);
        }
        
        queue<int> q;
	    int ans=0;
	    vector<int> indegree(n,0);
	    
	    for(int i=0;i<n;i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        ans++;
	        
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
        if(ans==n)
            return true;
        else
            return false;
        
    }
};