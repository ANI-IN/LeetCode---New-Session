class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        if(n<3)
        return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        //vowel , consonant, digit
        for(auto it : word)
        {
            if(!isalnum(it))
            return false;

            char ch = tolower(it);
            if(isalpha(ch))
            {
                if(ch =='a' || ch =='e' || ch =='i' || ch =='o' || ch =='u')
                hasVowel=true;
                else
                hasConsonant=true;
            }
        }

        return hasVowel && hasConsonant;
    }
};