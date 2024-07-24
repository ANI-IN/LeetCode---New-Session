class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
        
    DSU(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int findparent(int x)
    {
        if(parent[x]==x)
            return x;
        
        return parent[x]=findparent(parent[x]);
    }
    
    void unionbyrank(int u, int v)
    {
        int upu=findparent(u);
        int upv=findparent(v);
        
        if(upu == upv)
            return;
        if(rank[upu] < rank[upv])
        {
            parent[upu]=upv;
        }
        else if(rank[upu] > rank[upv])
        {
            parent[upv]=upu;
        }
        else
        {
            parent[upu]=upv;
            rank[upv]+=1;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        
        int extra=0;
         for(auto it : connections)
        {
            int u=it[0];
            int v=it[1];
            
            if(ds.findparent(u)==ds.findparent(v))
            {
                extra++;
            }
            else
            {
                ds.unionbyrank(u,v);
            }
        }
        
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
                c++;
        }
        c=c-1;
        
        if(extra>=c)
            return  c;
        else
            return -1;
        
        }
};