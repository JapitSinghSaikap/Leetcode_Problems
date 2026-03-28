// class Solution {
//     int lcs(String text1, String text2,int i,int j,int[][] dp){
//         if(i==text1.length() || j==text2.length()){
//             return 0;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];

//         int a=0;
//         int fc=0;
//         int sc=0;
//         if(text1.charAt(i)==text2.charAt(j)){
//             a=1+lcs(text1,text2,i+1,j+1,dp);
//         }else{
//             fc=lcs(text1,text2,i+1,j,dp);
//             sc=lcs(text1,text2,i,j+1,dp);
//             a=Math.max(fc,sc);
//         }
//         return dp[i][j]=a;
//     }
//     public int longestCommonSubsequence(String text1, String text2) {
//         int[][] dp = new int[text1.length()][text2.length()];
//         for(int[] d:dp){
//             Arrays.fill(d,-1);
//         }

//         return lcs(text1,text2,0,0,dp);
//     }
// }

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();

        int[][] dp = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    // Characters match: increase length by 1
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // Characters don't match: take max of left and top
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
}
