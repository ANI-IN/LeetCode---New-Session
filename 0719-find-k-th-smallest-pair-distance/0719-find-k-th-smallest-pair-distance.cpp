class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> arr(maxi+1,0);
        int n=nums.size();
        int counter=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int d=abs(nums[i]-nums[j]);
                arr[d]++;
            }
        }
        
        for(int d=0;d<maxi+1;d++)
        {
            k=k-arr[d];
            if(k<=0)
                return d;
        }
        return -1;
    }
};