class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> m;
        sort(begin(nums),end(nums));
        
        int streak=0;
        for(auto it : nums)
        {
            int root = (int)sqrt(it);
            if(root*root == it && m.find(root)!=m.end())
            {
                m[it]=1+m[root];
            }
            else
            {
                m[it]=1;
            }
            streak=max(streak,m[it]);
        }
        
        return streak>=2?streak:-1;
    }
};