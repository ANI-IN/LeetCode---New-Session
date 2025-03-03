class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> greater;
        vector<int> less;
        vector<int> eq;

        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
            {
                less.push_back(nums[i]);
            }
            else if(nums[i]==pivot)
            {
                eq.push_back(nums[i]);
            }
            else
            {
                greater.push_back(nums[i]);
            }
        }

        vector<int> ans;
        for(auto it : less)
        ans.push_back(it);
        for(auto it : eq)
        ans.push_back(it);
        for(auto it : greater)
        ans.push_back(it);

        return ans;
    }
};