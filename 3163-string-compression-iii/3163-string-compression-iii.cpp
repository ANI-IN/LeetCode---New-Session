class Solution {
public:
    string compressedString(string word) {
        string ans;
        int counter = 1;
        for(int i = 1; i < word.size(); i++){
            if(word[i] != word[i-1] || counter == 9){
                ans += to_string(counter) + word[i-1];
                counter = 0;
            }
            counter++;
        }

        if(counter > 0)ans += to_string(counter) + word[word.size()-1];
        
        return ans;
    }
};