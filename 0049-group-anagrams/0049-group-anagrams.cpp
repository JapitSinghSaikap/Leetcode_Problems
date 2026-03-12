class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        vector<vector<string>> ans;
        for(auto str:strs){
            string word = str;
            sort(word.begin(),word.end());
            mpp[word].push_back(str);
        }
        for(auto str:mpp){
            ans.push_back(str.second);
        }

        return ans;
    }
};



// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string,vector<string>> mpp;
//         vector<vector<string>> ans;

//         for(auto str : strs){
//             string word = str;
//             sort(word.begin(),word.end());
//             mpp[word].push_back(str);
//         }

//         for(auto str : mpp){
//             ans.push_back(str.second);
//         }

//         return ans;

//     }
// };