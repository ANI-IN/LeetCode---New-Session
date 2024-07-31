class Solution {
    int original;
    int solve(int index, int n, vector<vector<int>>&books, int w,int maxh,vector<vector<int>> &dp)
    {
        if(index>=n)
        {
            return maxh;
        }
        
        if(dp[index][w]!=-1)
            return dp[index][w];
        
        int take=INT_MAX;
        int skip=INT_MAX;
        
        int h=books[index][1];
        int t=books[index][0];
        
        if(t<=w)
        {
            take=solve(index+1,n,books,w-t,max(maxh,h),dp);
        }
        
        skip=maxh+solve(index+1,n,books,original-t,h,dp);
       
        return dp[index][w]=min(take,skip);
        
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        
        int w=shelfWidth;
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        original=w;
        int maxi=0;
        return solve(0,n,books,w,maxi,dp);
    }
};