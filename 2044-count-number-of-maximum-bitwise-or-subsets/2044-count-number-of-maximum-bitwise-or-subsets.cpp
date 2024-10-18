class Solution {
    int solve(int index,vector<int>&nums,int current_or, int maximum_or,vector<vector<int>> &dp)
    {
        if (index == nums.size()) {
            if (current_or == maximum_or) {
                return 1;
            }
            return 0 ;
        }
        
        if(dp[index][current_or]!=-1)
            return dp[index][current_or];
        
        int take = solve(index + 1, nums, current_or | nums[index], maximum_or, dp);
        int not_take = solve(index + 1, nums, current_or, maximum_or, dp);
        
        return dp[index][current_or] = take + not_take;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maximum_or=0;
        int n=nums.size();
        for(auto it : nums)
        {
            maximum_or = maximum_or | it;
        }
        
         
        vector<vector<int>> dp(n+1,vector<int>(maximum_or+1,-1));
        return solve(0,nums,0,maximum_or,dp);
         
    }
};