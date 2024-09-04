class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        int moveX[4]={0,1,0,-1};
        int moveY[4]={1,0,-1,0};
        
        // north 0, east 1, south 2, west 4
        
        set<pair<int,int>> st;
        for(auto it : obstacles)
        {
            int x=it[0];
            int y=it[1];
            st.insert({x,y});
        }
        
        
        int x=0,y=0,direction=0;
        int ans=0;
        
        for(auto it : commands)
        {
            if(it==-2)
            {
                direction=(direction+3)%4;
            }
            else if(it==-1)
            {
                direction=(direction+1)%4;
            }
            else
            {
                int moves=it;
                
                while(moves>0)
                {
                    int x_=x+moveX[direction];
                    int y_=y+moveY[direction];
                    
                    if(st.find({x_,y_})==st.end())
                    {
                        x=x_;
                        y=y_;
                        moves--;
                        ans=max(ans,(x*x)+(y*y));
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return ans;
        return ans;
    }
};