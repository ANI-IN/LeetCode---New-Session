class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m; 
        int len=0;
        for(int i=n-1;i>=0;i--)
        {
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]]++;
            }
            else
            {   
                len = i+1;
                break;
            }
        }

        if(len%3!=0)
        return (len/3)+1;
        else
        return len/3;
    }
};