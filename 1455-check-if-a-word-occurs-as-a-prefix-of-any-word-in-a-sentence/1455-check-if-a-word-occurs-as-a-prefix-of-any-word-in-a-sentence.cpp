class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string temp;
        int index = 1; 
        
        while (ss >> temp) {
            
            if (temp.find(searchWord) == 0) {
                return index;   
            }
            index++;
        }
        
        return -1;   
    }
};