class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int res=nums[0];

        for(int i=0;i<n;i++)
        {
            int pre=nums[i];
            res=max(res,pre);
            for(int j=i+1;j<n;j++)
            {
                pre=pre*nums[j];
                res=max(res,pre);
            }
            res=max(res,pre);
        }
        return res;
    }
};