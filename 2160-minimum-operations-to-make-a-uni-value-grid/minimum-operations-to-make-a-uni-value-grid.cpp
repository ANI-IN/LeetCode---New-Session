class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr.push_back(grid[i][j]);
            }
        }
        int mid=(arr.size())/2;
        
        sort(arr.begin(),arr.end());
        int e=arr[mid];
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
           int d = abs(arr[i]-e);
           if(d%x!=0)
           return -1;
           ans = ans + d/x;
        }

        return ans;
    }
};