class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26,0);
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            int c = s[i]-'a'; 
            mp[c]=i;
        }

        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            int j=i;
            int end = mp[s[i]-'a'];

            while(j<end)
            {
                end = max(end, mp[s[j]-'a']);
                j++;
            }
            ans.push_back(j-i+1);
            i=j;
        }
        return ans;
    }
};