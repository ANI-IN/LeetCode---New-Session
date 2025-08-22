class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int startrow=INT_MAX;
        int endrow=INT_MIN;

        int startcol=INT_MAX;
        int endcol=INT_MIN;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    startrow=min(startrow,i);
                    endrow=max(endrow,i);

                    startcol=min(startcol,j);
                    endcol=max(endcol,j);
                }
            }
        }

        int x=0,y=0;
        if(startrow!=INT_MAX && endrow!=INT_MIN)
        {
            x = endrow-startrow+1;
        }

        if(startcol!=INT_MAX && endcol!=INT_MIN)
        {
            y = endcol-startcol+1;
        }

        return x * y;

    }
};