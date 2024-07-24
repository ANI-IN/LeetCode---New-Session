class Solution {
    
    int solve(vector<vector<int>>&stones, int index, int &n, vector<bool>&visited)
    {
        visited[index]=true;       //Every time new stone visited marked it as true 
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            if( visited[i]==false &&  (stones[i][0]==stones[index][0] || stones[i][1] == stones[index][1]))     //check if it shares either the same row or the same column 
            {
                res=res+(solve(stones,i,n,visited)+1);
            }
        }
        return res;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n=stones.size();
        
        vector<bool> visited(n,0); // Initially all are set to false
        
        int ans=0;
        
        for(int i=0;i<n;i++)    // check for all stones
        {
            if(!visited[i])   // if not visited call the function 
            {
                ans=ans+solve(stones,i,n,visited);
            }
        }
        
        return ans;
        
    }
};