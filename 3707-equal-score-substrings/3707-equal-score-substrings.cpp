class Solution {
public:
    bool scoreBalance(string s) {
        // 1 + 4 + 3 + 2
        // 9 1 
        // 5 5 
        int totalScore = 0;
        for(char c : s){
            totalScore+=(c-'a'+1);
        }
        int firstHalf = totalScore;
        int secondHalf = 0;
        for(char c : s){
            int val  = c-'a'+1;
            firstHalf-=val;
            secondHalf+=val;
            if(firstHalf==secondHalf) return true; 
        }
        return false;

    }
};