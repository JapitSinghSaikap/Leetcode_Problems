class Solution {
public:
    bool hasAlternatingBits(int n) {
       unsigned long long x = n^(n>>1);
       return (x&(x+1)) == 0;   
    }
};