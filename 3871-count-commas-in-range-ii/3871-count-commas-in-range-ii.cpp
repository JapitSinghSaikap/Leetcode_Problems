class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000){
            return 0;
        }
        long long nv = n;
        long long count = 0;
        long long start = 1000;
        while(start <= nv){
            count+=nv-start+1;//count the comma's at that level
            start*=1000;//move to the next range
        }

        return count;
    }
};