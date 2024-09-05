class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total=rolls.size()+n;
        int sum=total*mean;
        int givenSum = accumulate(rolls.begin(), rolls.end(), 0);
        
        int avg=sum-givenSum;

         if (avg < n || avg > 6 * n) { 
            return {};
        }
        
        vector<int> result(n, avg / n); 
        int remainder = avg % n;
        
        for (int i = 0; i < remainder; ++i) {
            ++result[i]; 
        }
        
        return result;
    }
};