class Solution {
    int solve(int currA, int clip, int n,vector<vector<int>>&dp)
    {
        if(currA==n)
            return 0;
        if(currA>n)
            return 1e9;
        
        if(dp[currA][clip]!=-1)
            return dp[currA][clip];
        
        int copypaste=1+1+solve(currA+currA,currA,n,dp);
        int paste=1+solve(currA+clip,clip,n,dp);
        
        return dp[currA][clip]=min(copypaste,paste);
    }
public:
    int minSteps(int n) {
        if(n==1)
            return 0;
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        return 1+solve(1,1,n,dp);
    }
};