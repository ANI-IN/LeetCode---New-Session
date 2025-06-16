class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int maxdiff=-1;
        int mini=nums[0];

        for(int i=1;i<n;i++)
        {
            if(nums[i]>mini)
            {
                maxdiff=max(maxdiff,nums[i]-mini);
            }
            else
            {
                mini=min(mini,nums[i]);
            }
        }
        
        return maxdiff;
    }
};