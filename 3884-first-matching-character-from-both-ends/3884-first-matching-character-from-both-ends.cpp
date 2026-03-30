class Solution {
public:
    int firstMatchingIndex(string s) {
        //one from start and one from end l and r (two pinter approach)
        int l=0,h=s.length()-1;
        while(l<=h){
            if(s[l]==s[h]) return l;
            l++;h--;
        }
        return -1;
    }
};