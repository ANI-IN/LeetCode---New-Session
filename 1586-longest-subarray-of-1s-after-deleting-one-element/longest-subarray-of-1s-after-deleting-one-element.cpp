class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count=0;
        int ans=0;
        int n=nums.size();
        bool flag=false;
        int i=0,j=0;

        while(j<n)
        {
            if(nums[j]==1)
            {
                count++;
            }
            else if(flag==false)
            {
                flag=true;
            }
            else
            {
                while(flag)
                {
                    if(nums[i]==0)
                    {
                        i++;
                        break;
                    }
                    else
                    {
                        count--;
                    }
                    i++;
                }
            }
            ans=max(ans,count);
            j++;
        }

        if(ans==n)
        return ans-1;

        return ans;
        
    }
};