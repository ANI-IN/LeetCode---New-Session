class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
       double ans=0.0;
     vector<int> arr;

        int n = arr1.size();
        int m = arr2.size();
        int i=0,j=0;

        while(i<n && j<m)
        {
            if(arr1[i] <= arr2[j])
            {
                arr.push_back(arr1[i]);
                i++;
            }
            else
            {
                arr.push_back(arr2[j]);
                j++;
            }
        }

        while(i<n)
        {
            arr.push_back(arr1[i]);
            i++;
        }

        while(j<m)
        {
            arr.push_back(arr2[j]);
            j++;
        }
        
        
        n=arr.size();

        if(n%2==0)
        {
            ans = (arr[n/2]+arr[(n/2)-1])/2.0;
        }
        else
        {
            ans = (arr[n/2]);
        }
        return ans;
        
    }
};