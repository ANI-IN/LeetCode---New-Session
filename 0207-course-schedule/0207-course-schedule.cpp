class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        queue<int>q;
        int count=0;
        
        for(auto it : arr)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
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
            count++;
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                    
                }
            }
        }
        
        if(count!=n)
            return false;
        else
            return true;
       
        
        
    }
};