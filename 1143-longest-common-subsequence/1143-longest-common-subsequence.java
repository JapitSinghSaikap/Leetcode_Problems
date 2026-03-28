class Solution {
    int lcs(String text1, String text2,int i,int j,int[][] dp){
        if(i==text1.length() || j==text2.length()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int a=0;
        int fc=0;
        int sc=0;
        if(text1.charAt(i)==text2.charAt(j)){
            a=1+lcs(text1,text2,i+1,j+1,dp);
        }else{
            fc=lcs(text1,text2,i+1,j,dp);
            sc=lcs(text1,text2,i,j+1,dp);
            a=Math.max(fc,sc);
        }
        return dp[i][j]=a;
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length()][text2.length()];
        for(int[] d:dp){
            Arrays.fill(d,-1);
        }

        return lcs(text1,text2,0,0,dp);
    }
}