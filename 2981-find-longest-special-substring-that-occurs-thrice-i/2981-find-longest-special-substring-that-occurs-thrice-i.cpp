class Solution {
public:
    int maximumLength(string s) {
     int n=s.size();
        
        unordered_map<string,int> m;
        for(int i=0;i<n;i++)
        {
            string curr="";
            for(int j=i;j<n;j++)
            {
                if(curr.empty() || curr.back()==s[j])
                {
                    curr.push_back(s[j]);
                    m[curr]++;
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
            string str=it.first;
            if(it.second>=3 && str.size()>ans)
            {
                ans=str.size();
            }
        }
        return ans==0?-1:ans;
    }
};