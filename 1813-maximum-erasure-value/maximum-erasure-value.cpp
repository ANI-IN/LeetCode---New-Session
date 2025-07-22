class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;

        int i=0,j=0,n=nums.size();
        int ans=0;
        int sum=0;


        while(j<n)
        {
            m[nums[j]]++;
            sum+=nums[j];

            if(m.size()==j-i+1)
            {
                ans=max(ans,sum);
            }
            else
            {
                while(m.size()<j-i+1 && i<j)
                {
                    sum=sum-nums[i];
                    m[nums[i]]--;

                    if(m[nums[i]]==0)
                    {
                        m.erase(nums[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};