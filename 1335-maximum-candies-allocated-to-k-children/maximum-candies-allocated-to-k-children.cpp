#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long solve(vector<int>& candies, long long c) {  // c should be long long
        long long no = 0;
        for (int i = 0; i < candies.size(); i++) {
            no += candies[i] / c;  // Avoid overflow
        }
        return no;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL); // Use 0LL to avoid overflow
        if (sum < k) return 0;

        long long low = 1;
        long long high = *max_element(candies.begin(), candies.end());  // Use long long
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long child = solve(candies, mid);

            if (child < k) {
                high = mid - 1;
            } else {
                ans = mid;  // Store possible answer
                low = mid + 1;
            }
        }
        return ans;
    }
};
 