class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        
        vector<int> time;
        for(int i=0;i<n;i++){
            
            int hour=stoi(timePoints[i].substr(0,2));
         //   cout<<hour<<endl;
            int min=stoi(timePoints[i].substr(3,2));
           // cout<<min<<endl;
            //cout<<endl;
            
            int total=(hour*60)+min;
            cout<<total<<endl;
            time.push_back(total);
        }
        sort(time.begin(),time.end());
        int ans=INT_MAX;
        
        ans=min(ans,min(time[n-1]-time[0],1440-time[n-1]+time[0]));
        cout<<ans;
        
        for(int i=0;i<n-1;i++)
        {
            ans=min(ans,time[i+1]-time[i]);
        }
        
        
        
        return ans;
    }
};