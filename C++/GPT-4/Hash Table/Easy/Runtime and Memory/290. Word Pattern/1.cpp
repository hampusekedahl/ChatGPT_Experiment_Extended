#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        istringstream wordsStream(s);
        string word;
        int i = 0;
        for(; wordsStream >> word; ++i){
            if(i == pattern.size() || charToWord.count(pattern[i]) != wordToChar.count(word)){
                return false;
            }
            if(charToWord.count(pattern[i])){
                if(charToWord[pattern[i]] != word || wordToChar[word] != pattern[i]){
                    return false;
                }
            }
            else{
                charToWord[pattern[i]] = word;
                wordToChar[word] = pattern[i];
            }
        }
        return i == pattern.size();
    }
};
