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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n=edges.size();
        DSU ds(n+1);
        
        for(auto it : edges)
        {
            int u=it[0];
            int v=it[1];
            
            if(ds.find(u)==ds.find(v))
            {
                ans.push_back(u);
                ans.push_back(v);
            }
            else
            {
                ds.un(u,v);
            }
        }
        return ans;
    }
};