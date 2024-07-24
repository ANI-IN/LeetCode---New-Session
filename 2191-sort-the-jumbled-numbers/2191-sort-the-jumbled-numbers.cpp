class Solution {
    string solve(string s, vector<int>mapping)
    {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            int index=c-'0';
            int y=mapping[index];
            ans+=to_string(y);
        }
        return ans;
    }
        
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        vector<pair<int,int>> arr;
        
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            string s=to_string(num);
            string temp=solve(s,mapping);
            int x=stoi(temp);
            
            arr.push_back({x,i});
        }
        sort(arr.begin(),arr.end());
        vector<int> ans;
        
        for(auto it : arr)
        {
            ans.push_back(nums[it.second]);
        }
        return ans;
    }
};