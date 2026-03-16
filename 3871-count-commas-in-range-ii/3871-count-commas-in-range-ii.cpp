class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000){
            return 0;
        }
        long long e=n;
        long long k=0;
        long long s=1000;
        while(s<=e){
            k+=e-s+1;//count the comma's at that level
            s*=1000;//move to the next range
        }

        return k;
    }
};