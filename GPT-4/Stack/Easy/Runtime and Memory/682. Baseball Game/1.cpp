#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        int sum = 0;
        
        for (const string& op : operations) {
            if (op == "C") {
                sum -= record.back();
                record.pop_back();
            } else if (op == "D") {
                int new_score = record.back() * 2;
                sum += new_score;
                record.push_back(new_score);
            } else if (op == "+") {
                int new_score = record[record.size() - 1] + record[record.size() - 2];
                sum += new_score;
                record.push_back(new_score);
            } else {
                int new_score = stoi(op);
                sum += new_score;
                record.push_back(new_score);
            }
        }
        
        return sum;
    }
};
