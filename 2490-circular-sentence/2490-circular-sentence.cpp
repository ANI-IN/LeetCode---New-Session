class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string word,last,first;
        
        ss >> first;
        last=first;
        
        while(ss >> word)
        {
            if(last.back()!=word.front())
                return false;
            
            last=word;
        }
        
        if(last.back()!=first.front())
            return false;
        
        return true;
    }
};