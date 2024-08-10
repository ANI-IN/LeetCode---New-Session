class Solution {
    void solve(int i, int j, int size, vector<vector<int>>&arr)
    {   
        if(i<0 || i>=size || j<0 || j>=size || arr[i][j]==1)
            return;
        
        arr[i][j]=1;
        solve(i-1,j,size,arr);
        solve(i,j+1,size,arr);
        solve(i+1,j,size,arr);
        solve(i,j-1,size,arr);
        
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>> arr(n*3,vector<int>(n*3,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int r=3*i;
                int c=3*j;
                 
                if(grid[i][j]=='/')
                {
                    arr[r][c+2]=1;
                    arr[r+1][c+1]=1;
                    arr[r+2][c]=1;
                }
                else if(grid[i][j]=='\\')
                {
                    arr[r][c]=1;
                    arr[r+1][c+1]=1;
                    arr[r+2][c+2]=1;
                }       
            }
        }
        
        int res=0;
        
        for(int i=0;i<3*n;i++)
        {
            for(int j=0;j<3*n;j++)
            {
                if(arr[i][j]==0)
                {
                    res++;
                    solve(i,j,3*n,arr);
                }
            }
        }
        return res;
        
    }
};