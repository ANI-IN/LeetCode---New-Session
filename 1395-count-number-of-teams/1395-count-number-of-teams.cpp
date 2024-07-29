class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        
        int ans=0;
        
        for(int i=1;i<n-1;i++)
        {   
            int small=0;
            int big=0;
            
            int s=0;
            int b=0;
            
            int curr=rating[i];
            for(int j=0;j<i;j++)
            {
                if(rating[j] < curr)
                    small++;
                else if(rating[j]>curr)
                    b++;
            }
            for(int j=i+1;j<n;j++)
            {
                if(curr < rating[j])
                    big++;
                else if(rating[j] < curr)
                    s++;
            }
            cout<<small<<" "<<big<<endl; 
            ans=ans+(small*big)+(s*b);
        }
        return ans;
    }
};