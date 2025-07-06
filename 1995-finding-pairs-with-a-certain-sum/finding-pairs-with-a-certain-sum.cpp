class FindSumPairs {
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int,int> m;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;

        for(auto it : nums2)
        {
            m[it]++;
        }    
    }
    
    void add(int index, int val) {
        int old = nums2[index];
        m[old]--;

        nums2[index]+=val;
        m[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto it : nums1)
        {
            //1 + 2 = tot
            //2= tot-1

            int target = tot-it;

            ans+=m[target];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */