class Solution {
    int solve(int index, vector<int>&vis, vector<vector<int>>& stones)
    {
        vis[index]=1;
        int res=0;
        for(int i=0;i<stones.size();i++)
        {   
            int row=stones[i][0];
            int col=stones[i][1];
            
            if(!vis[i] && (stones[index][0]==row || stones[index][1] == col) )
               {
                   res=res+solve(i,vis,stones)+1;
               }
        }
        return res;
        
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans+=solve(i,vis,stones);
            }
        }
        return ans;
    }
};