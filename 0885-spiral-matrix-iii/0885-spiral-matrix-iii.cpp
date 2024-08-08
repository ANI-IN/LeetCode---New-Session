class Solution {
    
    bool issafe(int row, int col , int r, int c)
    {
        if(row>=0 && row<r && col>=0 && col<c)
            return true;
        else
            return false;
    }
    
public:
    vector<vector<int>> spiralMatrixIII(int r, int c, int rStart, int cStart) {
        
        int counter=1;
        vector<vector<int>> ans;
        
        int row=rStart,col=cStart;
        
        int delrow[]={0,+1,0,-1};
        int delcol[]={+1,0,-1,0};
        int step=0;
        ans.push_back({row,col});
        
        while(counter<r*c)
        {
            step++;
            for(int i=0;i<step;i++)
            {
                row+=delrow[0];
                col+=delcol[0];
               
                if(issafe(row,col,r,c))
                {
                    ans.push_back({row,col});
                    counter++;
                }
            }
            
            for(int i=0;i<step;i++)
            {
                row+=delrow[1];
                col+=delcol[1];
                
                if(issafe(row,col,r,c))
                {
                    ans.push_back({row,col});
                    counter++;
                }
            }
            step++;
            
            for(int i=0;i<step;i++)
            {
                row+=delrow[2];
                col+=delcol[2];
                
                if(issafe(row,col,r,c))
                {
                    ans.push_back({row,col});
                    counter++;
                }
            }
            
            for(int i=0;i<step;i++)
            {
                row+=delrow[3];
                col+=delcol[3];
                
                if(issafe(row,col,r,c))
                {
                    ans.push_back({row,col});
                    counter++;
                }
            }
        }
        return ans;
    }
};