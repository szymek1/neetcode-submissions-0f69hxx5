class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> grouped;

        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            grouped[key].push_back(s);
        }

        vector<vector<string>> results;
        for (auto& g : grouped) {
            results.push_back(move(g.second));
        }
        return results;
    }

};
