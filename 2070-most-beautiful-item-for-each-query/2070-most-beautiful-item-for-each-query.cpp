#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
         sort(items.begin(), items.end());

         vector<pair<int, int>> maxBeautyAtPrice;   
        int currentMaxBeauty = 0;
        for (const auto& item : items) {
            currentMaxBeauty = max(currentMaxBeauty, item[1]);
            maxBeautyAtPrice.push_back({item[0], currentMaxBeauty});
        }

         vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int query = queries[i];
            
            auto it = upper_bound(maxBeautyAtPrice.begin(), maxBeautyAtPrice.end(), make_pair(query, INT_MAX));
            if (it == maxBeautyAtPrice.begin()) {
                result[i] = 0;   
            } else {
                --it;   
                result[i] = it->second;   
            }
        }

        return result;
    }
};