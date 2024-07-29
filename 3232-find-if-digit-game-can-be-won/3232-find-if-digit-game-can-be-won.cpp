class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int s = 0; // Sum of numbers less than 10
        int d = 0; // Sum of numbers 10 or greater
        
        for (auto it : nums) {
            if (it < 10)
                s += it;
            else
                d += it;
        }
        
        cout << s << " " << d << endl; // Debug output for checking the sums
        
        if (s > d)
            return true;
        else if(d > s)
            return true;
        else
            return false;
    }
};
