class Solution {
public:    
    
   int form(int n, int k){
        if(n == 1 && k == 1) 
            return 0;
       
        int mid = (1 << (n-1));
       
        if(k < mid) 
            return form(n - 1, k);
        else if(k == mid) 
            return 1;
        else 
            return !( form(n - 1, (mid << 1) - k));
    }
    
    char findKthBit(int n, int k) {                       
        return (form(n,k) + '0');
    }
};