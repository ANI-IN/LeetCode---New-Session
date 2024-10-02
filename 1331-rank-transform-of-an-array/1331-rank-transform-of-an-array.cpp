class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> m;
        for(auto it : arr)
        {
            m[it]=0;
        }
        int rank=1;
        for(auto it : m)
        {
            m[it.first]=rank++;
        }
        vector<int> ans;
        for(auto it : arr)
        {
            ans.push_back(m[it]);
        }
        return ans;
        
    }
};