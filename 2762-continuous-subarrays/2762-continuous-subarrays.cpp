using ll = long long;
class Solution {
public:
    long long continuousSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        ll ct = 0, l = 0, r = 0, maxDiff = 0;
        multiset<ll> st;
        while (r < n) {
            if (st.size() > 0)
            {
                auto it = st.end();
                it--;
                int maxi = *it, mini = *st.begin();
                maxi = max(maxi, nums[r]);
                mini = min(mini, nums[r]);
                while (l < r && abs(maxi - mini) > 2 && st.size() > 0)
                {
                    if (st.find(nums[l]) != st.end())
                        st.erase(st.find(nums[l]));
                    l++;
                    if (st.size() == 0)
                        break;
                    auto it = st.end();
                    it--;
                    maxi = *it, mini = *st.begin();
                    maxi = max(maxi, nums[r]);
                    mini = min(mini, nums[r]);
                }
            }
            st.insert(nums[r]);
            ct += (r - l + 1);
            r++;
        }
        return ct;
    }
};