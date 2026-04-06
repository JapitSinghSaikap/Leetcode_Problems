class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0;
        int n=s.length();
        int maxf=0,maxLen=0;
        vector<int> mpp(256,0);
        while(r<n){
            mpp[s[r]-'A']++;
            maxf=max(maxf,mpp[s[r]-'A']);
            if(((r-l+1)-maxf)>k){
                mpp[s[l]-'A']--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        // r++;

        return maxLen;
    }
};