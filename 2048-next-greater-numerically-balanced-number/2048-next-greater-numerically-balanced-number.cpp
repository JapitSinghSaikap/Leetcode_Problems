class Solution {
public:
    bool isBeautiful(int n){
        vector<int>freq(10,0);
        while(n>0){
            int dig = n%10;
            freq[dig]++;
            n/=10;
        }
        for(int i=0;i<10;i++) {
            if(freq[i]!=0)
            if(freq[i]!=i) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1e7;i++){
            if(isBeautiful(i)) return i;
        }
        return -1;
    }
};