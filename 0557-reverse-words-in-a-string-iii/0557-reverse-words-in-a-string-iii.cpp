class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string curr="";

        for (int i=0;i<s.length();i++) {
            if (s[i]!=' ') {
                curr+=s[i];
            } else {
                reverse(curr.begin(), curr.end());
                ans+=curr;
                ans+=' ';
                curr="";
            }
        }

   
        if (!curr.empty()) {
            reverse(curr.begin(), curr.end());
            ans+=curr;
        }

        return ans;
    }
};