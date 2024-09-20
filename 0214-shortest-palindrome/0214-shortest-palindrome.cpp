class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string str=s;
        reverse(str.begin(),str.end());
        
        
        for(int i=0;i<n;i++)
        {
            if(!memcmp(s.c_str(),str.c_str()+i,n-i))
                return str.substr(0,i)+s;
        }
        
        return str+s;
    }
};