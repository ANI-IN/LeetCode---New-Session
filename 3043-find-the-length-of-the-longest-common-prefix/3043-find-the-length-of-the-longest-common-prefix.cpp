class Solution {
    int len(int num)
    {
        string s=to_string(num);
        return s.size();
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
       unordered_set<int> st;
        
        for(auto it : arr1)
        {
            while(it>0)
            {
                st.insert(it);
                it=it/10;
            }
        }
        
        int ans=0;
        
        for(auto it : arr2)
        {
            while(it>0)
            {
                if(st.find(it)!=st.end())
                {
                    ans=max(ans,len(it));
                    break;
                }
                
                it=it/10;    
            }
        }
        return ans;
        
    }
};