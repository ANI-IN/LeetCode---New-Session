class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0;
        int j=height.size()-1;
        
        int carea=0;
        int maxarea=0;
        
        while(i<j)
        {
            carea=(j-i)*(min(height[i],height[j]));
            
            if(maxarea<carea)
            {
                maxarea=carea;
            }
            if(height[i]<height[j])
            {
                i++;
            }
            else if( height[i]> height[j] )
            {
                j--;
            }
            else if( height[i]== height[j] )
            {
                i++;
            }
        }
        return maxarea;
    }
};