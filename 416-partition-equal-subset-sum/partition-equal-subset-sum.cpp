class Solution {
    bool solve(int i, vector<int>&nums, int target, vector<vector<int>>&dp)
    {   
        if(i>=nums.size())
        {   
            if(target==0)
            return true;
            else
            return false;
        }

        if(target==0)
            return true;

        if(target<0)
          return false;

        if(dp[i][target]!=-1)
        return dp[i][target];

      

        int pick = solve(i+1,nums,target-nums[i],dp);
        int non = solve(i+1,nums,target,dp);

        return dp[i][target]=pick||non;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
       
        for(auto it : nums)
        {
            sum+=it;
        }

        if(sum%2!=0)
        return false;

        int target=sum/2;
         vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};