class Solution {
    long long solve(int no , vector<int>&nums)
  {
    long long sum=0;
    for(int i=0;i<nums.size();i++)
    {
      sum = sum + (ceil)((double)nums[i]/(double)no);
    }
    return sum;
  }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=-1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(solve(mid,piles) <= h)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};