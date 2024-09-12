class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> m;
        for(auto it : allowed)
        {
            m[it]++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            string str=words[i];
            int flag=0;
            for(char c : str)
            {
                if(m.find(c)==m.end())
                    flag=1;
                    
            }
            if(!flag)
                ans++;
        }
        return ans;
    }
};