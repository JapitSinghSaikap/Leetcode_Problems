class Solution {
public:
    int countKeyChanges(string s) {
        for (char &c : s) {
            c=tolower(c);
        }

        int count=0;

        for (int i=1;i<s.size();i++) {
            if (s[i]!=s[i-1]) {
                count++;
            }
        }

        return count;

       
    }
};