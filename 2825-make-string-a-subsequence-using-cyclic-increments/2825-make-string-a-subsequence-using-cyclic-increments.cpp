class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str2index=0;
        int n=str1.size();
        int m=str2.size();
        
        for(int str1index=0; str1index<n && str2index<m ; str1index++)
        {
            if(str1[str1index] == str2[str2index] || (str1[str1index] + 1 == str2[str2index]) ||  (str1[str1index] - 25 == str2[str2index])) 
            {
                str2index++;
            }
        }
        
        return str2index==m;
    }
};