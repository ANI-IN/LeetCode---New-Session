class Solution {
    bool solve(vector<vector<int>> &mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        int c=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]!=c)
                    return false;
                
                c++;
                if(c==6)
                    return true;
            }
        }
        return true;
    }
    
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        queue<pair< pair<int,int>,vector<vector<int>> >> q;     //<int,int> vector<vector<int>>
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==0)
                {
                     q.push({{i,j},board});
                    break;
                }
            }
        }
        
        set<vector<vector<int>>> st;
        st.insert(board);
        int steps=0;
        
        while(!q.empty())
        {
            int size=q.size();
            
            while(size--)
            {
                auto temp = q.front();
                q.pop();

                int x= temp.first.first;
                int y=temp.first.second;

                if(solve(temp.second))
                {
                    return steps;
                }
                
                for(int i=0;i<4;i++)
                {
                    int nx=x + dx[i];
                    int ny=y + dy[i];
                    
                    if(nx>=0 && nx<n && ny>=0 && ny<m )
                    {
                        swap(temp.second[x][y],temp.second[nx][ny]);
                        if(st.find(temp.second)==st.end())
                        {
                            q.push({{nx,ny},temp.second});
                            st.insert(temp.second);
                        }
                        swap(temp.second[x][y],temp.second[nx][ny]);
                    }
                }
            }
            steps++;
        }
        return -1;
        
        
        
    }
};