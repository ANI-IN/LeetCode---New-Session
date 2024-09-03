class Solution {
    int solve(string &str)
    {
        int sum=0;
        for(int i=0;i<str.size();i++)
        {
            sum=sum+str[i]-'0';
        }
        str=to_string(sum);
        return sum;
    }
public:
    int getLucky(string s, int k) {
        int n=s.size();
        string str="";
        
        for(int i=0;i<n;i++)
        {
            int num=s[i]-'a'+1;
            str=str+to_string(num);
        }
        
        int sum=0;
        while(k--)
        {
            sum=solve(str);
        }
        return sum;
        
    }
};