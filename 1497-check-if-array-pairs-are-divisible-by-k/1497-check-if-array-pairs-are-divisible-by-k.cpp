class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> m;
        for(auto it : arr)
        {
            int rem=(it%k+k)%k;
            m[rem]++;
        }
        
        if(m[0]%2!=0)
            return false;
        
        for(int i=1;i<=k/2;i++)
        {
            int rem=k-i;
            if(m[i]!=m[rem])
                return false;
            
            
        }
        return true;
        
    }
};