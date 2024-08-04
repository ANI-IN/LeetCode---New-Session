class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    
      DSU(int n)
      {
          parent.resize(n);
          rank.resize(n,0);
          for(int i=0;i<n;i++)
          parent[i]=i;
      }
      
      int find(int x)
      {
          if(x==parent[x])
          return x;
          
          return parent[x]=find(parent[x]);
      }
      
      void un(int x, int y)
      {
          int px=find(x);
          int py=find(y);
          
          if(px==py)
          return;
          
          if(rank[px] < rank[py])
          {
              parent[px]=py;
          }
          else if(rank[px] > rank[py])
          {
              parent[py]=px;
          }
          else
          {
              parent[px]=py;
              rank[py]++;
          }
      }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& c) {
        int extra=0;
        DSU ds(n);
        for(auto it : c)
        {
            int u=it[0];
            int v=it[1];
            
            if(ds.find(u)==ds.find(v))
                extra++;
            else
                ds.un(u,v);
        }
        
        int left=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
                left++;
        }
        left--;
        
        if(left<=extra)
            return left;
        else
            return -1;
    }
};