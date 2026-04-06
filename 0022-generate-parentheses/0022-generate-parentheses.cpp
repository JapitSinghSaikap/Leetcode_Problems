class Solution {
public:
    void solve(int openN, int closedN, int n, string &curr, vector<string> &res) {
        // Base case agr 
        if (openN == n && closedN == n) {
            res.push_back(curr);
            return;
        }

        // Add '('
        if (openN < n) {
            curr.push_back('(');
            solve(openN + 1, closedN, n, curr, res);
            curr.pop_back();
        }

        // Add ')' this prevents condition like )( yeh generate hi nhi hota 
        if (closedN < openN) {
            curr.push_back(')');
            solve(openN, closedN + 1, n, curr, res);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr="";
        solve(0,0,n,curr,res);
        return res;
    }
};