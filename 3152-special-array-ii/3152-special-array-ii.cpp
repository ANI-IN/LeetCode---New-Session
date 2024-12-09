class Solution {
    bool solve(int start, int end, vector<int>&index)
    {
         int low=0,high=index.size()-1;
        
        while(low<=high)
        {
            int mid= low + (high-low)/2;
            int i = index[mid];
            
            if(i < start)
            {
                low = mid + 1;
            }
            else if(i> end)
            {
                high = mid-1;
            }
            else
                return true;
        }
        return false;
    }
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> index;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]%2==nums[i-1]%2)
                index.push_back(i);
        }
        
        for(int i=0;i<queries.size();i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            
            bool result = solve(start+1,end,index);
            if(result)
                ans.push_back(false);
            else
                ans.push_back(true);
        }
        return ans;
    }
};