// class Solution {
// public:
//     int bitwiseComplement(int n) {
//         int m=n;
//         int mask=0;
//         int ans;
//         if(m==0){
//             return 1;
//         }

//         while(m!=0){
//            mask=(mask<<1) | 1;
//            m= m>>1;
//         }
//         ans=(~n)&mask;
//         return ans;
//     }
// };
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string getBinary(int n){
        if(n == 0) return "";
        
        string res = getBinary(n / 2);
        
        int bit = n % 2;
        
        if(bit == 0)
            res += '1';
        else
            res += '0';
            
        return res;
    }

    int binaryToDecimal(string s){
        int num = 0;
        
        for(char c : s){
            num = num * 2 + (c - '0');
        }
        
        return num;
    }

    int bitwiseComplement(int num) {
        if(num == 0) return 1;

        string flipped = getBinary(num);
        return binaryToDecimal(flipped);
    }
};