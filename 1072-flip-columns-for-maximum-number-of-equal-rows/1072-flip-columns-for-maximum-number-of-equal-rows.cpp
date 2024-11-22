class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        unordered_map<string,int> mp;
        
        
        for(int i=0;i<n;i++)
        {   
            int curr=matrix[i][0];
            string check="";
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==curr)
                   check.push_back('s');
                else
                    check.push_back('b');
            }
            cout<<check<<endl;
            mp[check]++;
        }
        
        int ans=0;
        for(auto it : mp)
        {
            ans=max(ans,it.second);
        }
        return ans;
    }
};