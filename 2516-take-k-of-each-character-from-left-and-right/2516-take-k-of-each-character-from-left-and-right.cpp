class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        int ca=0;
        int cb=0;
        int cc=0;
        
        for(auto it : s)
        {
            if(it=='a')
                ca++;
            else if(it=='b')
                cb++;
            else 
                cc++;
        }
            
        
        if(ca < k || cb < k || cc < k)
            return -1;
        
        int i=0,j=0;
        
        int maxi=0;
        while(j<n)
        {
            if(s[j]=='a')
                ca--;
            else if(s[j]=='b')
                cb--;
            else if(s[j]=='c')
                cc--;
            
            while(i<=j && ca < k || cb < k || cc < k)
            {
                if(s[i]=='a')
                    ca++;
                else if(s[i]=='b')
                    cb++;
                else
                    cc++;
                
                i++;
            }
            
            maxi= max(maxi, j-i+1);
            j++;
        }
        return n-maxi;
    }
};