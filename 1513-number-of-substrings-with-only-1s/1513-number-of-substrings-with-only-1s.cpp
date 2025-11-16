class Solution {
public:
    int numSub(string s) {
        int l = 0;
        int r = 0;
        int mod = 1e9+7;
        int n = s.size();
        vector<int>freq(2,0);
        int total = 0;
        while(r<n){
            freq[s[r]-'0']++;
            while(freq[0]>=1){
                freq[s[l]-'0']--;
                l++;
            }
            total = (total + (r-l+1)%mod)%mod;
            r++;
        }
        return total;
    }
};