class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int g=0,e=0,l=0;
        for(auto it : nums)
        {
            if(it < pivot)
            l++;
            else if(it==pivot)
            e++;
            else
            g++;
        }

        cout<<l<<e<<g;

        int i=0,j=l,z=l+e;

        vector<int> ans(n);
        for(auto it : nums)
        {
            if(it < pivot)
            {
                ans[i]=it;
                i++;
            }
            else if(it==pivot)
            {
                ans[j]=it;
                j++;
            }
            else
            {
                ans[z]=it;
                z++;
            }
        }
        return ans;
    }
};