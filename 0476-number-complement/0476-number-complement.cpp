class Solution {
public:
    int findComplement(int num) {
        int no=(int)log2(num)+1;
     
        
        for(int i=0;i<no;i++)
        {
            num=num^(1<<i);
        }
        return num;
    }
};