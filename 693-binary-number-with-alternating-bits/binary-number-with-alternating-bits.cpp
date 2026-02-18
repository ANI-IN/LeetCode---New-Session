class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int current_bit=n%2;
        n=n/2;

        while(n)
        {
            int curr = n%2;
            if(curr == current_bit)
            return false;
            current_bit=curr;
            n=n/2;
        }
        return true;
    }
};