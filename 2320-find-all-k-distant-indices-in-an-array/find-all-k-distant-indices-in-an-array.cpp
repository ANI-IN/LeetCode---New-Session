class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();

        for(int i =0 ; i<n;i++)
        {
            if(nums[i]==key)
            {
                int start = max(i-k,0);
                int end = min(n-1,i+k);

                if(ans.empty())
                {   
                    for(int j=start;j<=end;j++)
                    ans.push_back(j);
                }
                else
                {       
                    if(ans.back()>=start)
                    {
                        start= ans.back()+1;
                    }
                    

                    for(int j=start;j<=end;j++)
                    ans.push_back(j);
                }
            }
        }   
        return ans;
    }
};