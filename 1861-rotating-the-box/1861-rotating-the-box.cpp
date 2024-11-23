class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int n=box.size();
        int m=box[0].size();
        vector<vector<char>> ans(m,vector<char>(n));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               ans[j][i]= box[i][j];
            }
        }
        
        n=ans.size();
        m=ans[0].size();
        
        for(int i=0;i<n;i++)
        {
            reverse(ans[i].begin(),ans[i].end());
        }
        
        
        for(int j=0;j<m;j++)
        {
            int index=n-1;
            for(int i=n-1;i>=0;i--)
            {
                if(ans[i][j]=='*')
                {
                    index=i-1;
                    continue;
                }
                
                if(ans[i][j]=='#')
                {
                    ans[i][j]='.';
                    ans[index][j]='#';
                    index--;
                }
            }
        }
        
        return ans;
    }
};