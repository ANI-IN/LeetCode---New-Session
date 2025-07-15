class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int rightsum=accumulate(nums.begin(),nums.end(),0);
        int leftsum=0;
        int index=-1;
         

        for(int i=0;i<n;i++)
        {
            rightsum-=nums[i];
            if(leftsum==rightsum)
            return i;

            leftsum+=nums[i];
        }
        return index;
    }
};