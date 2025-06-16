class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++)
        {   
            int maxi=-1;
            for(int j=i+1;j<n;j++)
            {
               if(nums[j]>nums[i])
               {
                maxi=max(maxi,nums[j]-nums[i]);
               }
            }
             
            ans=max(ans,maxi);
             
        }
        return ans;

    }
};