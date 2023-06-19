#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::istringstream ss(path);
        std::string token;

        while (std::getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(token);
            }
        }

        std::string canonical_path;
        for (const auto& dir : stack) {
            canonical_path += "/" + dir;
        }

        return canonical_path.empty() ? "/" : canonical_path;
    }
};
