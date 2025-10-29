// class Solution {
// public:
//the set bit numbers are 
//1 3 5 7 15 31  toh pattern hai k*2+1
//     int smallestNumber(int n) {
//         int k=1;
//         while(k<n){
//             k=2*k+1;
//         }

//         return k;
//     }
// };

//n & (n+1) == 0 to check if num is pow of 2 - 1 (saare set bits honge iske)

// class Solution {
// public:
// for 9 
//O(logn)
//O(1)
//     int smallestNumber(int n) {
//         while((n&(n+1))){
//           n = n | n+1;
//         }

//         return n;
//     }
// };

class Solution {
public:
    int smallestNumber(int n) {
       vector<int> arr = {1,3, 7, 15, 31, 63, 127, 255, 511, 1023};
       for(int it : arr) if(it>=n) return it;
       return -1;
    }
};