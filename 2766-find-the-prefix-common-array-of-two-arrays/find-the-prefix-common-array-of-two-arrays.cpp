class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        set<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {   
            st.insert(A[i]);
            int count=0;

            for(int j=i;j>=0;j--)
            {
                if(st.find(B[j])!=st.end())
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;

    }
};