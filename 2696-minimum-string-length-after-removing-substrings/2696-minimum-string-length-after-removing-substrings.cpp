class Solution {
public:
    int minLength(string s) {
       stack<char> st;
        
        
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(s[i]=='D' && st.top()=='C' && !st.empty())
            {
                st.pop();
            }
            else if(s[i]=='B' && st.top()=='A' && !st.empty())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.size();
    }
};