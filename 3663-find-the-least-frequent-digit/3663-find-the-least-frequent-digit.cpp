class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int,int>mpp;
        int minFreq = INT_MAX;
        int minFreqEl = -1;
        while(n>0){
            int temp = n%10;
            mpp[temp]++;
            n/=10;
        }
        for(auto it : mpp){
            if(minFreq>it.second){
                minFreq = it.second;
                minFreqEl = it.first;
            }
            else if(minFreq==it.second && minFreqEl>it.first){
                minFreqEl = it.first;
            }
        }
        return minFreqEl;
        
    }
};