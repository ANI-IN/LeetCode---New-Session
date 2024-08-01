class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        int n=details.size();
        for(int i=0;i<details.size();i++)
        {
            string str=details[i];
            string age=str.substr(11,2);
            int a=stoi(age);
            if(a>60)
                ans++;
        }
        return ans;
        
    }
};