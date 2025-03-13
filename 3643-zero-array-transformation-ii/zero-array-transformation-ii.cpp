class Solution {
    bool solve(vector<int>&nums, vector<vector<int>>&q,int k)
    {   
        int n=nums.size();
        vector<int> diff(n,0);

        for(int i=0;i<=k;i++)
        {
            int l=q[i][0];
            int r=q[i][1];
            int x=q[i][2];

            diff[l] +=x;
            if(r+1<n)
            diff[r+1] -=x; 
        }

        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum = sum + diff[i];
            diff[i] = sum;

            if(nums[i] - diff[i] >0)
            return false;
        }

        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        bool check=true;
        for(auto it : nums)
        {
            if(it!=0)
            {
                check=false;
                break;
            }
        }
        if(check)
        return 0;

        int l=0,r=queries.size()-1;
        int res=-1;
        while(l<=r)
        {
            int mid = l+ (r-l)/2;

            if(solve(nums,queries,mid))
            {
                res=mid+1;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return res;
    }
};