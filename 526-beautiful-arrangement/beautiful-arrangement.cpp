class Solution {
    int count=0;
    void solve(int pos, int n, vector<bool>&vis)
    {
        if(pos>n)
        {
            count++;
            return;
        }

        for(int i=1;i<=n;i++)
        {
            if(!vis[i] && (i%pos==0 || pos%i==0))
            {
                vis[i]=true;
                solve(pos+1,n,vis);
                vis[i]=false;
            }
        }
    }
public:
    int countArrangement(int n) {
        vector<bool> vis(n+1,false);

        solve(1,n,vis);
        return count;
    }
};