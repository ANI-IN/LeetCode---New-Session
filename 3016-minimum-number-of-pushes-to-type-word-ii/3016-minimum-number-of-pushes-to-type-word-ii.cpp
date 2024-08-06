class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26,0);
        for(int i=0;i<word.size();i++)
        {
            arr[word[i]-'a']++;
        }
        
        sort(arr.begin(),arr.end(),greater<int>());
        int sum=0;
        
        for(int i=0;i<26;i++)
        {
            int freq=arr[i];
            int press=(i/8)+1;
            sum+=press*freq;
        }
        return sum;
    }
};