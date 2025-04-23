class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,e1=0;
        int c2=0,e2=0;

        for(int i=0;i<nums.size();i++)
        {
            if(c1==0 && nums[i]!=e2)
            {
                c1 = 1;
                e1 = nums[i];
            }
            else if(c2==0 && nums[i]!=e1)
            {
                c2 = 1;
                e2 = nums[i];
            }
            else if(nums[i]==e1)
            {
                c1++;
            }
            else if(nums[i]==e2)
            {
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
        } 

        c1=0,c2=0;
        for(auto it : nums)
        {
            if(e1==it)
            c1++;
            else if(e2==it)
            c2++;
        }  

        int check = nums.size()/3+1;
        vector<int> ans;
        if(c1>=check)
        ans.push_back(e1);
        if(c2>=check && e2!=e1)
        ans.push_back(e2);

        return ans;
    }
};