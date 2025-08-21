class Solution {
    
    int solve(const vector<int>& vec) {
        int c = 0, con = 0;
        for (int v : vec) {
            con = (v == 1) ? (con + 1) : 0;
            c += con;
        }
        return c;
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();         
        int m = mat[0].size();      
        int res = 0;

        
        for (int left = 0; left < m; ++left) {
            vector<int> vec(n, 1);               
            for (int right = left; right < m; ++right) {
                for (int r = 0; r < n; ++r) {
                    vec[r] = vec[r] & mat[r][right];
                }
                res += solve(vec);              
            }
        }
        return res;
    }
};
