class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
       // stack<char> st;
        int size=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[')
            {
                size++;
            }
            else if(size > 0)
            {
                size--;
            }
        }
        
        return (size+1)/2;
        
        
    }
};