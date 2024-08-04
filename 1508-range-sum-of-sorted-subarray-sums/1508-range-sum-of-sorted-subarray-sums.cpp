class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j]; 
                arr.push_back(sum);
                cout<<sum<<" ";
            }
        }
        const int mod=1e9+7;
      //  sort(arr.begin(),arr.end());
        sort(arr.begin(), arr.end());
        long long sumsum=accumulate(arr.begin()+left-1, arr.begin()+right, 0LL)%mod;

        return sumsum;
    }
};