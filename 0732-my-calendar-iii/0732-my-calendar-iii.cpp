class MyCalendarThree {
public:
    map<int,int> m;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        m[startTime]++;
        m[endTime]--;
        int maxi=0;
        int sum=0;
        for(auto it : m)
        {
            sum+=it.second;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */