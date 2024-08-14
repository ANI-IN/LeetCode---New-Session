class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // Sort the input array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int left = 0;
        int right = nums[n-1] - nums[0];
        
        // Binary search on the distance
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0, j = 0;
            
            // Count pairs with distance less than or equal to mid
            for (int i = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= mid) {
                    ++j;
                }
                count += j - i - 1;
            }
            
            // Adjust binary search range based on count
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};
