class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int first_minimum=INT_MAX;
        int second_minimum=INT_MAX;

        for(int i=1;i<n;i++)
        {
            if(nums[i]<first_minimum)
            {
                second_minimum=first_minimum;
                first_minimum=nums[i];
            }
            else if(nums[i]<second_minimum)
            {
                second_minimum=nums[i];
            }
        }

        int score = nums[0] + first_minimum + second_minimum;

        return score;
    }
};