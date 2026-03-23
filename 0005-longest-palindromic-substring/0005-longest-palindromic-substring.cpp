class Solution {
public: 
    bool palli(string &s, int i, int j){//for checking if the substr is pallindrome or not
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }            
    
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int max = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(palli(s, i, j)){
                    //r-l+1 hi hai yeh
                    if(j-i+1 > max){//for getting the max pallindrome substr
                        max = j-i+1;
                        start = i;//reset start us value pe
                    }
                }
            }
        }
        return s.substr(start, max);
    }
}; 