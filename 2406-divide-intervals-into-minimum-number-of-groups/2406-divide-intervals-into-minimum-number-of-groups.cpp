class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        priority_queue<int, vector<int>,greater<int>>q;
        
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<n;i++)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];
            
            if(!q.empty() && start > q.top())
            {
                q.pop();
            }
            q.push(end);
        }
        return q.size();
    }
};