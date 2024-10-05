class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        sort(begin(s1),end(s1));
        int m=s2.size();
        
        for(int i=0;i<=m-n;i++)
        {
            string str = s2.substr(i,n);
            sort(begin(str),end(str));
            
            if(str==s1)
                return true;
                
        }
        return false;
    }
};