#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for(int index = 0; index < words.size(); ++index){
            string word = words[index];
            for(int i = 0; i <= word.size(); i++) {
                for(int j = 0; j <= word.size(); j++) {
                    string prefix = word.substr(0, i);
                    string suffix = word.substr(word.size()-j, j);
                    map[prefix+'_'+suffix] = index;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        string key = pref + "_" + suff;
        if(map.find(key) != map.end())
            return map[key];
        else
            return -1;
    }
private:
    unordered_map<string, int> map;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
