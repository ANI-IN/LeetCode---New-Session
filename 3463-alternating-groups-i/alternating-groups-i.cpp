class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size();
        int ans=0;
        int left,right;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                left=colors[n-1];
                right=colors[i+1];
            }
            else if(i==n-1)
            {
                left=colors[i-1];
                right=colors[0];
            }
            else
            {
                left=colors[i-1];
                right=colors[i+1];
            }

            if(left!=colors[i] && right!=colors[i])
            ans++;
        }
        return ans;
    }
};