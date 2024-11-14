class Solution {
    int solve(int mid, vector<int>&quantities)
    {
        int count=0;
        for(int i=0;i<quantities.size();i++)
        {
            count += (quantities[i] + mid - 1) / mid;

        }
        return count;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        sort(quantities.begin(),quantities.end());
        
        int low=1;
        int high=*max_element(quantities.begin(), quantities.end());
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int x = solve(mid,quantities);
            
            if(x<=n)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
        
    }
};