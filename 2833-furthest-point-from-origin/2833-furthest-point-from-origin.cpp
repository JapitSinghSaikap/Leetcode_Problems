class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int n=s.length();
        int l=0;
        int r=0;
        int us=0;
        for(int i=0;i<n;i++){
            if(s[i]=='R') r++;
            if(s[i]=='L') l++;
            if(s[i]=='_') us++;
        }
        return abs(r-l)+us;
    }
};