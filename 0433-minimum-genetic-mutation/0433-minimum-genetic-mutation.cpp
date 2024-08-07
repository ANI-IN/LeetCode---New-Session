class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n=bank.size();
        unordered_set<string> visited;
        unordered_set<string> b;
        
        for(auto it : bank)
            b.insert(it);
        
        int level=0;
        
        queue<string> q;
        q.push(startGene);
        
        visited.insert(startGene);
        
        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                string str=q.front();
                q.pop();
                
                 if (str == endGene)
                    return level;
                
                for(int j=0;j<str.size();j++)
                {
                   for(char ch : "ACGT")
                    {
                        char original=str[j];

                        str[j]=ch;

                        if(visited.find(str)==visited.end() && b.find(str)!=b.end())
                        {
                            visited.insert(str);
                            q.push(str);
                        }
                        str[j]=original;
                    }  
                }
               
            }
            level++;
        }
        
        return -1;;
        
    }
};