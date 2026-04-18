class Solution {
public:
    string reverseNum(int n){
        string num="";
        while(n!=0){
            int digit=n%10;
            num+=(digit+'0');
            n/=10;
        }
        return num;
    }
    int mirrorDistance(int n) {
        string rev = reverseNum(n);
        int check=stoi(rev);
        return abs(n-check);
    }
};