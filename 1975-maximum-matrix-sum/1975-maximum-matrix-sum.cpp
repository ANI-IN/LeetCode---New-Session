class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=INT_MAX;
        long long even=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]<0)
                    even++;
                ans+=abs(matrix[i][j]);
                mini=min(mini,abs(matrix[i][j]));
            }
        }
        
        cout<<ans<<endl;
        cout<<even<<endl;
        cout<<mini<<endl;
        
        if(even%2==0)
            return ans;
        else
            return ans-(2*mini);
        
    }
};