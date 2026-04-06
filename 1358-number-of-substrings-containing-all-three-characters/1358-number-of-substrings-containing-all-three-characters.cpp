class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0;
        int cnt=0;
        int n=s.size();
        vector<int> mpp(3,0);
        while(r<n){
            mpp[s[r]-'a']++;
            while(mpp[0]>=1 && mpp[1]>=1 && mpp[2]>=1 ){
                cnt+=(n-r);
                mpp[s[l]-'a']--;
                l++;
            }
            r++;
        }

        return cnt;
    }
};