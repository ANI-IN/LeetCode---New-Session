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
    bool equationsPossible(vector<string>& e) {
        
        int n=e.size();
        DSU ds(26);
        
        for(int i=0;i<n;i++)
        {
            string str=e[i];
            int u=str[0]-'a';
            int v=str[3]-'a';
            
            if(str[1]=='=')
            {
                ds.un(u,v);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            string str=e[i];
            int u=str[0]-'a';
            int v=str[3]-'a';
            
            if(str[1]=='!')
            {
                if(ds.find(u)==ds.find(v))
                    return false;
            }
        }
        
        
        
        return true;
    }
};