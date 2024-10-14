class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(auto it : nums)
            q.push(it);
        long long ans=0;
        
        while(k--)
        {
           long long it  = q.top();
            q.pop();
            ans= ans + it;
            
            it = ceil(it/3.0);
            q.push(it);
        }
        return ans;
    }
};