class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int e=0;
        int maxi=0;

        for(int i=0;i<n;i++)
        {
            if(maxi==0)
            {
                e=nums[i];
                maxi++;
            }
            else if(e==nums[i])
            {
                maxi++;
            }
            else
            {
                maxi--;
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==e)
            count++;
        }
        
        int firste=0;
        int laste=n;
        for(int i=0;i<n;i++)
        {
            int first=i+1;
            int last=n-i-1;

            if(nums[i]==e)
            {
                firste++;
            }

            laste = count - firste;
            if(firste > first/2 && laste > last/2)
            return i;
        }
        return -1;
        
    }
};