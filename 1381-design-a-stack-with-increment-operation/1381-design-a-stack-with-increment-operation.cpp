class CustomStack {
public:
    vector<int> arr;
    int i,j,n;
    CustomStack(int maxSize) {
        arr.resize(maxSize,0);
        i=0,j=0;
        n=maxSize;
    }
    
    void push(int x) {
        if(j>=n)
            return;
        else
        {
            arr[j++]=x;
        }
    }
    
    int pop() {
        int val;
        if(j>0)
        {
            val=arr[--j];
        }
        else if(j==-1)
        {
            return -1;
        }
        else
        {
            return -1;
        }
        return val;
    }
    
    void increment(int k, int val) {
        
        for(int element=0 ; element< min(k,j);element++)
        {
            arr[element]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */