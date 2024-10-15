class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        int i=0,j=n-1;
        
        
        long long steps=0;
        long long t=0;
        for(long long i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                t++;
            }
            else
            {
                steps+=t;
            }
        }
        return steps;
    }
};