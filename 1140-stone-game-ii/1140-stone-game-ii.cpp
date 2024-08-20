class Solution {
    int solve(int i, int m , vector<int>&piles, vector<vector<int>>&dp)
    {
        if(i>=piles.size())
            return 0;
        
        if(dp[i][m]!=-1)
            return dp[i][m];
            
            int tot=0;
            int ans=INT_MIN;
            for(int j=0;j<2*m;j++)
            {
                if(i+j<piles.size())
                {
                    tot=tot+piles[i+j];
                    ans=max(ans,tot-solve(i+j+1,max(m,j+1),piles,dp));
                }
            }
        
           return dp[i][m]=ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(101,vector<int> (201,-1));
        int sum=0;
        for(auto it : piles)
            sum+=it;
        
        int diff=solve(0,1,piles,dp);
        
        return (sum+diff)/2;
        
    }
};