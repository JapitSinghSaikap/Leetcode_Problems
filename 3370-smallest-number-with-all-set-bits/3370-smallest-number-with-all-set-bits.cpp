class Solution {
public:
//the set bit numbers are 
//1 3 5 7 15 31  toh pattern hai k*2+1
    int smallestNumber(int n) {
        int k=1;
        while(k<n){
            k=2*k+1;
        }

        return k;
    }
};