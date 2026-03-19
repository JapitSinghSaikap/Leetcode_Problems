class Solution {
    void tile(string tiles, unordered_set<string>& forcount, string& temp, unordered_set<int>& idx) {
        if (temp.length() > tiles.length()) {
            return;
        }
        if (!temp.empty() && forcount.find(temp) == forcount.end()) {
            forcount.insert(temp);
        }
        for (int i = 0; i < tiles.length(); i++) {
            if (idx.find(i) == idx.end()) {
                temp.push_back(tiles[i]);
                idx.insert(i);
                tile(tiles, forcount, temp, idx);
                temp.pop_back(); // backtrack
                idx.erase(i);
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> forcount;
        unordered_set<int> idx;
        string temp = "";
        tile(tiles, forcount, temp, idx);
        return forcount.size();
    }
};