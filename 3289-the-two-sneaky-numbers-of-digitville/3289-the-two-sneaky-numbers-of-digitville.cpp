class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(auto it : nums)
        {
            if(m.find(it)!=m.end())
            {
                ans.push_back(it);
            }
            m[it]++;
        }
        return ans;
    }
};