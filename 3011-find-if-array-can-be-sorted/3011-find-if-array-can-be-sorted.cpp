class Solution {
public:
    bool canSortArray(vector<int>& arr) {
        
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                int x=__builtin_popcount(arr[j]);
                int y=__builtin_popcount(arr[j+1]);
                if(arr[j] > arr[j+1] && x==y)
                {
                    swap(arr[j],arr[j+1]);
                }
                else if (arr[j] > arr[j + 1] && x != y) {
                    return false;
                }
            }
        }
        return true;
    }
};