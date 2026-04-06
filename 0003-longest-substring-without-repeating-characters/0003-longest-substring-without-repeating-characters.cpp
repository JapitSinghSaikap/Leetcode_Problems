class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;

        int l=0;
        int maxLen=0;
        for(int r=0;r<s.length();r++){
            while(mpp.count(s[r])){
                mpp.erase(s[l]);
                l++;
            }

            mpp[s[r]]++;

            maxLen=max(maxLen,r-l+1);
        }

        return maxLen;
    }
};