class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;

        int mini=-1,maxi=-1;
        int f=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxK || nums[i] <minK)
            f=i;


            if(nums[i]==minK)
            mini=i;

            if(nums[i]==maxK)
            maxi=i;

            int count = min(mini,maxi)-f;
            ans+=(count<=0)?0:count;
        }
        return ans;
    }
};