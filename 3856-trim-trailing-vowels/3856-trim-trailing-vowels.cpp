class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char> trail = {'a','e','i','o','u'};
        int idx=s.size()-1;
        while(idx>=0){
            if(trail.count(s[idx])!=0){
                idx--;
            }
            else break;
        }
        return s.substr(0,idx+1);
    }
};