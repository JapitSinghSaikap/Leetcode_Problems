class Solution {
public:
    int minFlips(string s) {
        int k = s.size();
        s = s + s;
        char flag1 = '0',flag2 = '1',st1 = '0',st2 = '1';
        int left = 0,right = 0,ch1 = 0,ch2 = 0,result = 1e9;
        while(right < s.size()){
            if(s[right]!=flag1) ch1++;
            if(s[right]!=flag2) ch2++;
            flag1 = (flag1=='0')?'1':'0';
            flag2 = (flag2=='0')?'1':'0';
            if(right-left+1>k){
                if(s[left]!=st1) ch1--;
                if(s[left]!=st2) ch2--;
                left++;
                st1 = (st1=='0')?'1':'0';
                st2 = (st2=='0')?'1':'0';
            }
            if(right-left+1==k){
                int diff = min(ch1,ch2);
                result = min(result,diff);
            }
            right++;
        }        
        return result;
    }
};