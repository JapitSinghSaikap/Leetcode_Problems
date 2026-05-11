class Solution {
    public int minFlips(String s) {
        int zeroes = 0;
        int ones = 0;
        int res = (int)1e5;
        for(int i=0;i<s.length();i++) {
            char c = s.charAt(i);
            if(c=='0') zeroes++;
            else ones++;
        }
        if(ones==1) return 0;
        res= Math.min(ones,zeroes);
        int l=0;
        int r=s.length()-1;
        boolean flag=false;
        if(s.charAt(l)=='1' && s.charAt(r)=='1' && l<r) {
            res = Math.min(res,ones-2);
            flag=  true;
        }
        if(s.charAt(l)=='1' || s.charAt(r)=='1'){
            res = Math.min(res,ones-1);
            if(!flag) {
                int temp =1;
                int centerOnes = ones-1;
                int centerZeroes =  zeroes-1;
                temp+=Math.min(centerOnes,centerZeroes);
                res =  Math.min(res,temp);
            }
        }
        
        
        if(s.charAt(l)!='1' && s.charAt(r)!='1' && ones>1) {
            res = Math.min(res,ones-1);
        }
        return res;
    }
}
