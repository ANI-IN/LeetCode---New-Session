class Solution {
public:
    int maximumLength(string s) {
     int n=s.size();
        
        map<pair<char, int>, int> m;
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            string curr="";
            int len=0;
            for(int j=i;j<n;j++)
            {
                if(c == s[j])
                {
                    len++;
                    m[{c,len}]++;
                }
                else
                {
                    break;
                }
            }
        }
        
        int ans=0;
        for(auto it : m)
        {
            int len=it.first.second;
            if(it.second>=3 && len>ans)
            {
                ans=len;
            }
        }
        return ans==0?-1:ans;
    }
};