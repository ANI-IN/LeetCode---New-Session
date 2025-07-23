class Solution {
    string solve(string str, string pattern)
    {
        int i =0;

        for(int j=0;j<str.size();j++)
        {
            str[i] = str[j];
            i++;

            if(i>=2 && str[i-2]==pattern[0] && str[i-1]==pattern[1])
            {
                i=i-2;
            }
        }

        str.erase(begin(str)+i,end(str));
        return str;
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