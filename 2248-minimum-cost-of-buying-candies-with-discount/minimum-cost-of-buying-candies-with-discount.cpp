class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int ans=0;

        int n=cost.size();

        for(int i=0;i<n;i++)
        {
            if((i+1)%3==0)
            continue;

            ans+=cost[i];
        }
        return ans;
    }
};