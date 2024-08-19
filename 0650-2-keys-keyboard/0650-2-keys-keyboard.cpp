class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(1001,0);
        
        dp[0]=0;
        dp[1]=0;
        dp[2]=2;
        dp[3]=3;
        
        for(int i=4;i<=n;i++)
        {
            int factor=i/2;
            
            while(factor>=1)
            {
                if(i%factor==0)
                {
                    int y=dp[factor];
                    int copy=1;
                    int paste=(i/factor)-1;
                    
                    dp[i]=y+copy+paste;
                    break;
                }
                else
                {
                    factor--;
                }
            }
        }
        return dp[n];
    }
};