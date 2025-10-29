class Solution {
public:
    int smallestNumber(int n) {
        
        int res=1;
        if(n==1)
        return 1;
        while((2*res+1)<n)
        {
            res=2*res+1;
        }
        res=2*res+1;
        return res;
    }
};