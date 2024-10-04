class Solution {
    typedef long long ll;
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(begin(skill),end(skill));
        if(n==2)
        {
            return skill[0]*skill[1];
        }
        
        ll sum=skill[0]+skill[n-1];
        
        ll ans=skill[0]*skill[n-1];
        ll i=1,j=n-2;
        
        while(i<j)
        {
            ll curr=skill[i]+skill[j];
            if(curr!=sum)
                return -1;
            
            ans=ans + (skill[i]*skill[j]);
            i++;
            j--;
        }
        return ans;
    }
};