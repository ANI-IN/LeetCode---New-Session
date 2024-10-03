class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=(sum+(nums[i]))%p;
        }
        sum=sum%p;
        int target=sum%p;
        if(target==0)
            return 0;
        
        
        unordered_map<int,int> m;
        m[0]=-1;
        int ans=n;
        int curr=0;
        for(int j=0;j<n;j++)
        {
            curr=(curr+nums[j])%p;
            int f=(curr-target+p)%p;
                if(m.find(f)!=m.end())
                {
                    ans=min(ans,j-m[f]);
                }
            
            m[curr]=j;
        }
        if(ans!=n)
            return ans;
        else
            return -1;
    }
};