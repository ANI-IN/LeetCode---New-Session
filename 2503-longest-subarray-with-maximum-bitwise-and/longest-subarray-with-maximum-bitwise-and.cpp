class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int curr=0;
        int n=nums.size();
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] > maxi)
            {
                maxi=nums[i];
                curr=1;
                ans=1;
            }
            else if(nums[i] == maxi)
            {
                curr++;
            }
            else
            {
                curr=0;
            }
            ans=max(ans,curr);  
            
        }
        return ans;
    }
};