class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        int i=0,j=0;
        long long temp=0;
        
        while(j<n)
        {
            temp = temp + nums[j];
            mp[nums[j]]++;
            
            while(j-i+1>k)
            {
                temp = temp - nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            
            if(j-i+1==k && mp.size()==k)
            {
                    sum = max(sum , temp);  
            }
            
            j++;
        }
        return sum;
    }
};