class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> arr;
        vector<string>ans;
        for(int i=0;i<names.size();i++)
        {
            arr.push_back({heights[i],names[i]});
        }
        sort(arr.begin(),arr.end(),greater<pair<int,string>>());
        for(auto it: arr)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};