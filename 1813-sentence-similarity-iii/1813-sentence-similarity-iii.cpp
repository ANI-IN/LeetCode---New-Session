class Solution {
public:
    bool areSentencesSimilar(string str1, string str2) {
        vector<string> v1;
        vector<string> v2;
        
        if(str1.size() < str2.size())
        {
            swap(str1,str2);
        }
        
        stringstream ss1(str1);
        stringstream ss2(str2);
           
           string token="";
           
           while(ss1 >>token)
           {
               v1.push_back(token);
           }
           
           token="";
           while(ss2 >>token)
           {
               v2.push_back(token);
           }
           
        
        int i=0,j=v1.size()-1;
        int k=0,l=v2.size()-1;
           
           
           while(i <= j && k<=l)
           {
               if(v1[i] == v2[k])
               {
                   i++;
                   k++;
               }
               else if(v1[i] != v2[k])
               {
                   if(v1[j] == v2[l])
                   {
                       j--;
                       l--;
                   }
                   else
                   {
                       break;
                   }
               }
           }
           
           return k>l?true:false;
        
    }
};