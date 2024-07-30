class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        
        int ans=0;
        
        
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty() && s[i]=='a' && st.top()=='b')
            {
                ans++;
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        return ans;
    }
};