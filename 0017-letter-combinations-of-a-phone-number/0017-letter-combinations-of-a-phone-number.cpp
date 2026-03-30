class Solution {
public:
    vector<string>ans;
    void solve(int index , string &s , string& temp , vector<string>&mpp){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }
        string val = mpp[s[index]-'0'];
        for(char c : val){
            temp.push_back(c);
            solve(index+1,s,temp,mpp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
        if(s.empty()) return {};
        vector<string>mpp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp="";
        solve(0,s,temp,mpp);
        return ans;
    }
};