class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
       string ans="";
        
        priority_queue<pair<int,char>> q;
        if(a>0)
            q.push({a,'a'});
        
        if(b>0)
            q.push({b,'b'});
        
        if(c>0)
            q.push({c,'c'});
        
        while(!q.empty())
        {
            int freq= q.top().first;
            char ch = q.top().second;
            q.pop();
            
            if(ans.size()>=2 && ans[ans.size()-1]==ch && ans[ans.size()-2]==ch)
            {
                if(q.empty())
                    break;
                
                int freqq=q.top().first;
                char c=q.top().second;
                q.pop();
                
                freqq--;
                ans.push_back(c);
                
                if(freqq>0)
                q.push({freqq,c});
            }
            else
            {
                freq--;
                ans.push_back(ch);
            }
            
                if(freq>0)
                    q.push({freq,ch});
        }
        return ans;
    }
};