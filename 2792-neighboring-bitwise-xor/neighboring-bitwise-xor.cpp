class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();

        vector<int> arr(n);
        arr[0]=0;
        for(int i=1;i<n;i++)
        {
            arr[i] = arr[i-1]^derived[i-1];
        }

        if((arr[n-1] ^ arr[0]) == derived[n-1])
        return true;

        vector<int> arr1(n);
        arr1[0]=1;
        for(int i=1;i<n;i++)
        {
            arr1[i] = arr1[i-1]^derived[i-1];
        }

        if((arr1[n-1] ^ arr1[0]) == derived[n-1])
        return true;

        return false;

    }
};