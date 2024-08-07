class Solution {
    int dfs(int index, vector<int>&vis,vector<vector<int>>&stones)
    {
        vis[index]=1;
        int res=0;
        for(int i=0;i<stones.size();i++)
        {
            if(!vis[i] && (stones[index][0] == stones[i][0] || stones[index][1]==stones[i][1]))
            {
                res=res+dfs(i,vis,stones)+1;
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
                ans+=dfs(i,vis,stones);
            }
        }
        return ans;
    }
};