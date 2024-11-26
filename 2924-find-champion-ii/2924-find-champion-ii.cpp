class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<int> adj[n];
        
        for(auto it : edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int> indegree(n,0);
        
        int ans=-1;
        int count=0;
        
        for(int i=0;i<n;i++)
        {   
            cout<<"parent "<<i<<endl;
            for(auto it : adj[i])
            {
                 
                 
                indegree[it]++;
                cout<<" adjancent "<<it<<endl;
            }
            cout<<endl;
        }
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                count++;
                ans=i;
            }
        }
        
        return count==1 ? ans : -1;
    }
};