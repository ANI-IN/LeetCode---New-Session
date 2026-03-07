class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s=s+s;
         

        string one = "";
        string zero = "";

        int check=1;
        for(int i=0;i<2*n;i++)
        {
            if(check)
            {
                one.push_back('1');
                zero.push_back('0');
                check=!check;
            }
            else
            {
                one.push_back('0');
                zero.push_back('1');
                check=!check;
            }
        }

        int i=0,j=0,size=2*n;

        int c1=0,c2=0;
        int ans=n;

        while(j<size)
        {       
            if(s[j]!=one[j])
            c1++;
            if(s[j]!=zero[j])
            c2++;

            
            if(j-i+1==n)
            {
                ans=min(c1,c2);
            }

            if(j-i+1>n)
            {
                if(s[i]!=one[i])
                {
                    c1--;
                }

                 if(s[i]!=zero[i])
                 {
                    c2--;
                 }
                 i++;
            }

             if (j - i + 1 == n) {
                ans = min(ans, min(c1, c2));
            }

            j++;
        }

        return ans;

    }
};