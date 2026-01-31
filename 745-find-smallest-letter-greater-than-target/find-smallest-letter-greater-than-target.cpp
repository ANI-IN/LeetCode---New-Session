class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(),letters.end());


        for(auto it : letters)
        {
            if(it>target)
            return it ;
        }

        return letters[0];
    }
};