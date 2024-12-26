class Solution {
      int dp[21][2001];
    
    int solve(int index, vector<int>&arr, int &S, int sum)
    {
        if(index==arr.size())
            return sum==S?1:0;
        
        if(dp[index][sum+1000]!=-1)
            return dp[index][sum+1000];
        
        int p=solve(index+1,arr,S,sum+arr[index]);
        int n=solve(index+1,arr,S,sum-arr[index]);
        return dp[index][sum+1000] = p+n;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
         memset(dp,-1,sizeof(dp));
         return solve(0,nums,S,0);
    }
};