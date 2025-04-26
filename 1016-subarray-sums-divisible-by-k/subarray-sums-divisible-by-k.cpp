class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,sum=0;
        unordered_map<int,int> m;
        
        m[0]=1;
        int ans=0;
        while(j<n)
        {
            sum += nums[j];
            int rem = sum%k;

            if(rem<0)
            {
                rem+=k;
            }
 
            if(m.find(rem)!=m.end())
            {
                ans+=m[rem];
            }
            m[rem]++;
            j++;
        }
        return ans;
    }
};