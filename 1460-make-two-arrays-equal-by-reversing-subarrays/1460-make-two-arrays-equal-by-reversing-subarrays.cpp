class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> m;
        int n=target.size(),mm=arr.size();
        if(n!=mm)
            return false;
        
        for(int i=0;i<n;i++)
        {
            m[target[i]]++;
            m[arr[i]]--;
        }
        
        for(auto it : m)
        {    cout<<it.first<<" "<<it.second<<endl;
            if(it.second!=0)
                return false;
        }
    
        return true;
            
    }
};