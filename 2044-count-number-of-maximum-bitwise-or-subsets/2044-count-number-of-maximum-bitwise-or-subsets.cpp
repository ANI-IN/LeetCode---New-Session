class Solution {
    void solve(int index,vector<int>&nums,int current_or, int maximum_or, int &count)
    {
        if (index == nums.size()) {
            if (current_or == maximum_or) {
                count++;
            }
            return;
        }
        
         
        solve(index + 1, nums, current_or | nums[index], maximum_or, count);
        
         
        solve(index + 1, nums, current_or, maximum_or, count);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maximum_or=0;
        
        for(auto it : nums)
        {
            maximum_or = maximum_or | it;
        }
        int count=0;
        int n=nums.size();
        
        solve(0,nums,0,maximum_or,count);
        return count;
    }
};