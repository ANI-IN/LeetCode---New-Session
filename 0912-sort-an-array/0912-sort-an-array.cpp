class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int>q;
        for(auto it : nums)
        {
            q.push(it);
        }
        vector<int> ans(n,0);
        while(!q.empty())
        {
            int num=q.top();
            q.pop();
            ans[n-1]=num;
            n--;
        }
        return ans;
    }
};