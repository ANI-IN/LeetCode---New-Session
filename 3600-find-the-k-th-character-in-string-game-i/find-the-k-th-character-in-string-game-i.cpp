class Solution {
public:
    char kthCharacter(int k) {
        string start = "a";

        while(k>=start.size())
        {
            int n = start.size();
            string temp;
            for(int i=0;i<n;i++)
            {
                temp.push_back(start[i]+1);
            }
            start+=temp;

            if(k<=start.size())
            {
                return start[k-1];
            }
        }
        return 1;
    }
};