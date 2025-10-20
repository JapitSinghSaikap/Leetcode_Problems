class Solution {
public:
    bool isNegative(string s){
        if(s[0]=='-' || s[2]=='-') return true;
        return false;
    }
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for(string s : operations){
            if(isNegative(s)) val--;
            else val++;
        }
        return val;
    }
};