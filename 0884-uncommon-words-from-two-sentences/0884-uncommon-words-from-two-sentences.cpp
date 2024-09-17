class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        stringstream ss(s1);
        unordered_map<string,int>m;
        
        string token;
        
        while(ss >> token)
        {
            m[token]++;
        }
        
        stringstream curr(s2);
        string str="";
        
        while(curr >> str)
        {
            m[str]++;
        }
        
        for(auto it : m)
        {
            if(it.second==1)
                ans.push_back(it.first);
        }
        return ans;
        
    }
};