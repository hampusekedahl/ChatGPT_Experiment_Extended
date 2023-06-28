#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string reverseWords(std::string s) {
        // Trim the input string
        s.erase(0, s.find_first_not_of(' ')); // Trim leading spaces
        s.erase(s.find_last_not_of(' ') + 1); // Trim trailing spaces

        std::istringstream iss(s);
        std::vector<std::string> words;
        std::string word;

        // Split the input string into words
        while (iss >> word) {
            words.push_back(word);
        }

        // Reverse the order of the words
        std::reverse(words.begin(), words.end());

        // Concatenate the words with a single space
        std::string result;
        for (const auto& w : words) {
            result += w + " ";
        }

        // Remove the last space
        result.pop_back();

        return result;
    }
};
