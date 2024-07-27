class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size();
        vector<vector<int>> dist(26,vector<int>(26,1e9));
        
        for(int i=0;i<26;i++)
            dist[i][i]=0;
        
        for(int i=0;i<n;i++)
        {
            int x=original[i]-'a';
            int y=changed[i]-'a';
            dist[x][y]=min(dist[x][y],cost[i]);
        }
        
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(dist[i][k]==1e9 || dist[k][j]==1e9)
                        continue;
                    
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        long long sum=0;
        
        
        for(int i=0;i<source.size();i++)
        {
            if(source[i]==target[i])
                continue;
            
            int x=source[i]-'a';
            int y=target[i]-'a';
            
            if(dist[x][y]!=1e9)
            sum=sum+dist[x][y];
            else
                return -1;
        }
        
        return sum;
        
    }
};