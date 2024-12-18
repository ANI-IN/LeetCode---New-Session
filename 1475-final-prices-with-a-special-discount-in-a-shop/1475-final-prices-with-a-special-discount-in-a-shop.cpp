class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int res=prices[i];
            int check=0;
            for(int j=i+1;j<n;j++)
            {
                if(prices[i]>=prices[j])
                {
                    check=1;
                    res=res-prices[j];
                    break;
                }
            }
            if(check==1)
            {
                ans.push_back(res);
            }
            else
            {
                ans.push_back(prices[i]);
            }
        }
        return ans;
    }
};