class Solution {
    void solve(int i, int j, int c, int color, vector<vector<int>> &ans,vector<vector<int>> image,int delRow[],int delCol[])
    {
        ans[i][j]=color;
        for(int k=0;k<4;k++)
        {
            int dr=i+delRow[k];
            int dc=j+delCol[k];
                
                if(dr<image.size() && dr>=0 && dc<image[0].size() && dc>=0 && image[dr][dc]==c && ans[dr][dc]!=color)
                    solve(dr,dc,c,color,ans,image,delRow,delCol);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int c=image[sr][sc];
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        
        solve(sr,sc,c,color,ans,image,delRow,delCol);
        return ans;
        
    }
};