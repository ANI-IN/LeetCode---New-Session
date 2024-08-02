class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int size=0;
     
        for(auto it : nums)
        {
            if(it==1)
                size++;
        }
        
        if(size==0)
            return 0;
        
        int i=0,j=0,n=nums.size()*2;
        int mod=nums.size();
        int swap=0;
        int ans=INT_MAX;

        while(j<n*2)
        {
            if(nums[j%mod]==0)
            {
                swap++;
            }
            if(j-i+1==size)
            {
                ans=min(ans,swap);
            }
            while(j-i+1>=size)
            {
                if(nums[i%mod]==0)
                    swap--;
                i++;
            }
            j++;
        }
        return ans;
    }
};