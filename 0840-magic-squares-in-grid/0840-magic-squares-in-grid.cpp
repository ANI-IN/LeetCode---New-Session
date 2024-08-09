class Solution {
    int solve(int i, int j, vector<vector<int>>&grid)
    {
        int n=grid.size();
        
        int c=grid[0].size();
        
        int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2];
        
        vector<int> count(10,0);
        
        
        for(int row=i; row<i+3;row++)
        {
            for(int col=j; col<j+3;col++)
            {
                int num=grid[row][col];
                    if(num > 9 || num < 1)
                        return 0;
                    count[num]++;
            }
        }
        
        
        for(int k=1;k<=9;k++)
        {
            if(count[k]!=1)
                return 0;
        }
        
        for(int row=i ; row<i+3; row++)
        {
            if((grid[row][j] + grid[row][j+1] + grid[row][j+2])!=sum)
                return 0;
        }
        
        for(int col=j ; col<j+3; col++)
        {
            if((grid[i][col] + grid[i+1][col] + grid[i+2][col])!=sum)
                return 0;
        }
        
        if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != sum) return 0;
        if (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != sum) return 0;
        
        return 1;
        
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        
        
        for(int i=0;i<=r-3;i++)
        {
            for(int j=0;j<=c-3;j++)
            {   
                ans=ans+solve(i,j,grid);
            }
        }
        return ans;
    }
};