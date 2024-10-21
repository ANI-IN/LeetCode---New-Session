class Solution {
    void solve(int index, string s, int curr, int&ans, set<string>&st)
    {
        if(index>=s.size())
        {
            ans=max(ans,curr);
            return;
        }
        
        for(int j=index;j<s.size();j++)
        {
            string str=s.substr(index,j-index+1);
            if(st.find(str)==st.end())
            {
                st.insert(str);
                solve(j+1,s,curr+1,ans,st);
                st.erase(str);
            }
        }

        }
public:
    int maxUniqueSplit(string s) {
        int curr=0,ans=0;
        set<string>st;
        solve(0,s,curr,ans,st);
        return ans;
    }
};