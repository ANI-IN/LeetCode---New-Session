class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> prefix=arr;
        vector<int> suffix=arr;
        
        prefix[0]=arr[0];
        suffix[n-1]=arr[n-1];
        
        for(int i=1;i<n;i++)
        {
            prefix[i] = max(prefix[i-1],arr[i]);
             
        }
        
        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = min(suffix[i+1],suffix[i]);
        }
        int ans=0;
        
        for(int i=0;i<n;i++)
            cout<<suffix[i]<<" ";
        cout<<endl;
        
     
        for(int i=0;i<n;i++)
        {
            if(i==0 || suffix[i] > prefix[i-1])
                ans++;
        }
         
        
        return ans;
    }
};