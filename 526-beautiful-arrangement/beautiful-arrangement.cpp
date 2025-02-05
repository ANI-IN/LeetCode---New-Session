class Solution {
    int count = 0;
    void findArrangements(int pos, int n, vector<bool>& used) {
    if (pos > n) { 
        count++;  // Found a valid arrangement
        return;
    }

    for (int num = 1; num <= n; num++) {
        if (!used[num] && (num % pos == 0 || pos % num == 0)) { 
            used[num] = true;  // Mark number as used
            findArrangements(pos + 1, n, used);
            used[num] = false;  // Backtrack
        }
    }
}

public:
    int countArrangement(int n) {
         vector<bool> used(n + 1, false);
            count = 0;
            findArrangements(1, n, used);
            return count;
    }
};