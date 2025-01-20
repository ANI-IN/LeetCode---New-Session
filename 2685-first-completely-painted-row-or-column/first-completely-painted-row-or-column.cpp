class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<int> row(n,m);
        vector<int> col(m,n);

        cout<<n<<" "<<m<<endl;

        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                mp[mat[i][j]] = {i, j};
            }
        }

        for(int i=0;i<arr.size();i++)
        {
            int element = arr[i];
            int index=i;

            int r=mp[element].first;
            int c=mp[element].second;

            row[r]--;
            col[c]--;

            if(row[r]==0)
            return i;

            if(col[c]==0)
            return i;
        }
        return arr.size();
    }
};