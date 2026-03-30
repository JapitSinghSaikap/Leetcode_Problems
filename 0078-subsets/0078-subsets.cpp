class Solution {
public:
    void subsetRecur(int i, vector<int>& arr, 
       vector<vector<int>>& res, vector<int>& subset) {
    if (i == arr.size()) {
        res.push_back(subset);
        return;
    }
    //inlcluding the current value
    subset.push_back(arr[i]);
    subsetRecur(i+1, arr, res, subset);
    //excluding the current value and uske baad saari explor ki
    subset.pop_back();
    subsetRecur(i+1, arr, res, subset);
    }
    
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int> subset;
        vector<vector<int>> res;
        subsetRecur(0, arr, res, subset);
        return res;
    }
};

