class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[grid[i][j]]++;
            }
        }

        int r=0,mi=0;
        for(int i=1;i<=n*n;i++)
        {
            if(!mp.count(i))
            mi=i;
            else if(mp[i]==2)
            r=i;
        }
        return {r,mi};
    }
};