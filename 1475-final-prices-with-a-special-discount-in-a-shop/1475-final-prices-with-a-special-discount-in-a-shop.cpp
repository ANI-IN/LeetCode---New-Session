class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n=prices.size();
        vector<int> ans;
        for(auto it : prices)
            ans.push_back(it);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && prices[i] <=prices[st.top()])
            {
                ans[st.top()] = ans[st.top()] - prices[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};