#include <unordered_map>
#include <sstream>
#include <vector>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        vector<string> words;
        
        stringstream str(s);
        string word;
        
        // Split the string into words
        while(str >> word) {
            words.push_back(word);
        }
        
        if(pattern.size() != words.size()) {
            return false;   // if pattern and words counts are not equal
        }
        
        for(int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            
            if(charToWord.count(c) && charToWord[c] != words[i]) {
                return false;   // if char already mapped to some other word
            }
            
            if(wordToChar.count(words[i]) && wordToChar[words[i]] != c) {
                return false;   // if word already mapped to some other char
            }
            
            charToWord[c] = words[i];
            wordToChar[words[i]] = c;
        }
        
        return true;
    }
};
