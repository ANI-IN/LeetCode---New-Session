class Solution {
    string solve(string str, string pattern)
    {
        stack<char> st;
        int count=0;
        int n=str.size();

        for(int i=0;i<n;i++)
        {
            if(!st.empty() && st.top()==pattern[0] && str[i]==pattern[1])
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }

        string temp = "";
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(),temp.end());
        return temp;
    }
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        int score=0;

        string maxi = (x>y) ? "ab" : "ba";
        string mini = (maxi=="ab") ? "ba" : "ab";

        //first pass
     
        string str = solve(s,maxi);
        int L = str.size();
        int remove = (n-L);
        score = score + (remove/2)*max(x,y);
        //second pass


        string temp = solve(str,mini);
        int sz = temp.size();
        remove = (L-sz);
        score = score + (remove/2)*min(x,y);

        return score;
     }
};