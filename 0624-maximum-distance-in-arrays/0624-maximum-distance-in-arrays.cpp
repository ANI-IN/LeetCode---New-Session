class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();
        
        int maxi=arrays[0].back();
        int mini=arrays[0][0];
        
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int x=arrays[i][0];
            int y=arrays[i].back();
            
            ans=max(ans,abs(maxi-x));
            ans=max(ans,abs(mini-y));
            
            maxi=max(maxi,y);
            mini=min(mini,x);
        }
        return ans;
    }
};