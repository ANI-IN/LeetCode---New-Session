class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        
        for(int i=0;i<n;i++)
        {
            dist[i][i]=0;
        }
        
        for(auto it : edges)
        {
            int i=it[0];
            int j=it[1];
            int w=it[2];
            dist[i][j]=w;
            dist[j][i]=w;
        }
        
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {   
                     if(dist[i][k]==1e9 || dist[k][j]==1e9)
                        continue;
                     dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                   cout<<dist[i][j]<<" ";
                }
                cout<<endl;
            }
        
        int maxi=n;
        int city=0;
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]<=t)
                    c++;
            }
            if(maxi>=c)
            {
                maxi=c;
                city=i;    
            }
        }
        return city;
        
    }
};