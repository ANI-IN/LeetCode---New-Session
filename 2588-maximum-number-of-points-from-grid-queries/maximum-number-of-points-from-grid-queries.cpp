class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();
        int m=grid[0].size();
        int dr[] = {0,-1,0,+1};
        int dc[] = {-1,0,+1,0};
        vector<int> ans(queries.size(),0);
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<pair<int,int>> vc;
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>> > > q;
        
        
        for(int i=0;i<queries.size();i++)
        {
            vc.push_back({queries[i],i});
        }
        sort(vc.begin(),vc.end());
q.push({grid[0][0],{0,0}});
        
        visited[0][0]=1;

        int res=0;

        for(int i=0;i<vc.size();i++)
        {   
            int val = vc[i].first;
            int index = vc[i].second;
            while(!q.empty() && q.top().first < val)
            {
                int r = q.top().second.first;
                int c = q.top().second.second;
                q.pop();

                res++;

                for(int j=0;j<4;j++)
                {
                    int nr = r + dr[j];
                    int nc = c + dc[j];

                    if(nr>=0 && nr<n && nc>=0 && nc<m &&  !visited[nr][nc])
                    {
                        visited[nr][nc]=1;
                        q.push({grid[nr][nc],{nr,nc}});
                    }
                }
            }

            ans[index]= res;

        }
        return ans;
              
    }
};