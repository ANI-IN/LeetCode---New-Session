class Solution {
    bool isdigit(char c)
    {
        if(c>='0' && c<='9')
            return true;
        else
            return false;
    }
    
public:
    string fractionAddition(string exp) {
        int n=exp.size();
        int num=0;
        int den=1;
        int i=0;
        while(i<n)
        {
            int currnum=0;
            int currden=0;
            bool neg=false;
            
            if(exp[i]=='-')
            {
                neg=true;
                i++;
            }
            else if(exp[i]=='+')
            {
                i++;
            }
            
            
            while(i<n && isdigit(exp[i]))
            {
                currnum=currnum*10+(exp[i]-'0');
                i++;
            }
            
            
            i++;
            
            if(neg)
                currnum=-1*currnum;
            
            while(i<n && isdigit(exp[i]))
            {
                currden=currden*10+(exp[i]-'0');
                i++;
            }
            
            num=num*currden+currnum*den;
            den=den*currden;
            
            
        }
        
        int gcd=abs(__gcd(num,den));
        num/=gcd;
        den/=gcd;
        
        string ans=to_string(num)+"/"+to_string(den);
        return ans;
    }
};