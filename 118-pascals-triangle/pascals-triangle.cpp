class Solution {
    vector<int> generateRow(int r)
    {
        long long ans =1 ;
        vector<int> temp;
        temp.push_back(1);

        for(int col=1; col<r ; col++ )
        {
            ans = ans * (r - col);
            ans = ans / col;
            temp.push_back(ans);
        }
        return temp;
    }
public:
    vector<vector<int>> generate(int numRows) {
        int rows=numRows;
        vector<vector<int>> ans;
        for(int i=1;i<=rows;i++)
        {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};