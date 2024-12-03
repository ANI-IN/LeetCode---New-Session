class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        stringstream ss;
        int index=0;
        for(int i=0;i<s.size();i++)
        {
            if(index<spaces.size() && i==spaces[index])
            {
                ss << ' ';
                index++;
            }
            ss << s[i];
        }
        return ss.str();
    }
};