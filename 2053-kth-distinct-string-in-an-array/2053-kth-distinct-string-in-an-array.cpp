class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> m;
        for(auto it : arr)
            m[it]++;
        
        
        for(int i=0;i<arr.size();i++)
        {
            string str=arr[i];
            
            if(m[str]==1)
                k--;
            if(k==0)
            {
                return str;
            }
        }
        return "";
    }
};