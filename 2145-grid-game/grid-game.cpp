class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m=grid[0].size();
        long long row1sum=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long row2=0;

        long long ans=LONG_LONG_MAX;
        for(int i=0;i<m;i++)
        {
            row1sum = row1sum - grid[0][i];
            long long robo2= max (row1sum,row2);

            ans = min(ans,robo2);
            row2 += grid[1][i];
        }
        return ans;

    }
};