class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freetime;

        freetime.push_back(startTime[0]-0);
        int n=startTime.size();
        for(int i=1;i<n;i++)
        {
            freetime.push_back(startTime[i]-endTime[i-1]);
        }
        freetime.push_back(eventTime-endTime[n-1]);

        n=freetime.size();
        int ans=0;
        int i=0;
        int j=0;
        int curr=0;


        while(j<n)
        {
            curr+=freetime[j];

            if(j-i+1>k+1)
            {
                curr=curr-freetime[i];
                i++;
            }
            ans=max(curr,ans);
            j++;
        }
        return ans;
    }
};