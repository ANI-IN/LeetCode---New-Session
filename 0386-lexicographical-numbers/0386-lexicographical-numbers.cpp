class Solution {
    void solve(int num, int n, vector<int>&ans)
    {
        if(num>n)
            return;
        
        ans.push_back(num);
        
        for(int i=0;i<=9;i++)
        {
            int newnumber= num*10 + i;
            if(newnumber >n)
                return;
            solve(newnumber,n,ans);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        
        for(int i=1;i<=9;i++)
        {
            solve(i,n,ans);
        }
        return ans;
    }
};