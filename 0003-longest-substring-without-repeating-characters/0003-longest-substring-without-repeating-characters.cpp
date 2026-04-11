class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> mpp;
        int l=0;
        int maxLen=0;
        for(int r=0;r<n;r++){
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