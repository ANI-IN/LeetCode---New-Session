class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq;  

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int x : nums2) {
            freq[x]++;
        }
    }
    
    void add(int index, int val) {
        int oldValue = nums2[index];
        freq[oldValue]--;
        nums2[index] += val;
        freq[nums2[index]]++;
    }
    
    int count(int tot) {
        int result = 0;
        for (int x : nums1) {
            int complement = tot - x;
            result += freq[complement];
        }
        return result;
    }
};
