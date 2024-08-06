class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        
        unordered_map<char,int> m;
        
        int ans=0;
        int count=0;
        for(int i=0;i<word.size();i++)
        {
            char c=word[i];
            
            if(m.find(c)==m.end())
            {
                if(count>=0 && count<8)
                {
                    m[c]=1;
                }
                else if(count>=8 && count<16)
                {
                    m[c]=2;
                }
                else if(count>=16 && count<24)
                {
                    m[c]=3;
                }
                else
                {
                    m[c]=4;
                }
                count++;
            }
        }
        
        for(auto it : word)
        {
            ans=ans+m[it];
        }
        return ans;
    }
};