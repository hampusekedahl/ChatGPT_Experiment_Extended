#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleLen = needle.length();
        int haystackLen = haystack.length();

        if (needleLen == 0) {
            return 0;
        }

        // Create the longest prefix-suffix (LPS) array for the needle
        vector<int> lps = createLPSArray(needle);

        int i = 0; // Index for haystack
        int j = 0; // Index for needle

        while (i < haystackLen) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == needleLen) {
                return i - j;
            } else if (i < haystackLen && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }

private:
    vector<int> createLPSArray(string pattern) {
        int patternLen = pattern.length();
        vector<int> lps(patternLen, 0);
        int len = 0; // Length of the previous longest prefix-suffix
        int i = 1;

        while (i < patternLen) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }
};
