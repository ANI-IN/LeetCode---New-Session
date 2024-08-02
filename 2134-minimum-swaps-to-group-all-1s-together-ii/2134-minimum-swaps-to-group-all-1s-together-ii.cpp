class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int size=0;
        vector<int> temp=nums;
        
        for(auto it : nums)
        {
            if(it==1)
                size++;
           temp.push_back(it);
        }
        if(size==0)
            return 0;
        
        int i=0,j=0,n=nums.size()*2;
        
        int swap=0;
        int ans=INT_MAX;

        while(j<n)
        {
            if(temp[j]==0)
            {
                swap++;
            }
            if(j-i+1==size)
            {
                ans=min(ans,swap);
            }
            while(j-i+1>=size)
            {
                if(temp[i]==0)
                    swap--;
                i++;
            }
            j++;
        }
        return ans;
    }
};