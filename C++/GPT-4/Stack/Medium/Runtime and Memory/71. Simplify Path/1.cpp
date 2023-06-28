#include <stack>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathStack;
        stringstream ss(path);
        string segment;
        
        while (getline(ss, segment, '/')) {
            if (segment == "" || segment == ".") {
                continue;
            } else if (segment == "..") {
                if (!pathStack.empty()) {
                    pathStack.pop();
                }
            } else {
                pathStack.push(segment);
            }
        }
        
        string canonicalPath = "";
        while (!pathStack.empty()) {
            canonicalPath = "/" + pathStack.top() + canonicalPath;
            pathStack.pop();
        }
        
        return canonicalPath.empty() ? "/" : canonicalPath;
    }
};
