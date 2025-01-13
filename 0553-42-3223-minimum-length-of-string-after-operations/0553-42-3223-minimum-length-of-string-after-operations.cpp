class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        vector<int> a(26,0);
         
        int ans=0;
        for(int i=0;i<n;i++)
        {
           a[s[i]-'a']++;

           if(a[s[i]-'a']==3)
           {
            a[s[i]-'a']-=2;
            ans = ans + 2;
           }
           
        }
        return n-ans;
    }
};