class Solution {
public:
    int minCost(int n) {
        int mincost=0;
        while(n>1){
            mincost+=n-1;
            n=n-1;
        }
    return mincost;
    }
};