class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({nums[i],i});
        }
        sort(begin(arr),end(arr));

        int low=0,high=n-1;

        while(low<=high)
        {
            int sum = arr[low].first + arr[high].first;
             
            if(sum > target)
            {
                high--;
            } 
            else if(sum < target)
            {
                low++;
            }
            else
            {
                return {arr[low].second,arr[high].second};
            }
        }
        return {-1,-1};
    }
};