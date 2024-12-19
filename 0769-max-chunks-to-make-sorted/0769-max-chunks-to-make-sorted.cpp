class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        int pre=0,suff=0;
        for(int i=0;i<n;i++)
        {
            pre+=arr[i];
            suff+=i;
            
            if(pre==suff)
                ans++;
        }
        return ans;
    }
};