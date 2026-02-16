class Solution {
public:
    const int MOD=1e9+7;
    int countTexts(string str) {
        int n=str.length();
        vector<long long>dp(n+1,0);
        dp[n]=1;

        for(int i=n-1;i>=0;i--){
            long long count=0;
            int check=0;
            if(str[i]=='7' || str[i]=='9') check=4;
            else check=3;

            for(int j=i;j<n && j<i+check && str[j]==str[i];j++){
                count=(count+dp[j+1])%MOD;

            }

            dp[i]=count;
        }
        return dp[0];
    }
};


// class Solution {
// public:
//     const int MOD=1e9+7;
//     long long f(int ind,string str,vector<int>& dp){
        
//         int n=str.length();
//         if(ind==n) return 1;
//         if(dp[ind]!=-1) return dp[ind];

//         long long count=0;
//         int check = 0;
//         if(str[ind]=='9' || str[ind]=='7'){
//             check=4;
//         }else{
//             check=3;
//         }

//         for(int j=ind;j<n && j<ind+check && str[j]==str[ind];j++){
//             count = (count+f(j+1,str,dp))%MOD;
//         }

//         return dp[ind]=count;

//     }
//     int countTexts(string str) {
//         int n=str.length();
//         vector<int> dp(n,-1);
//         return f(0,str,dp);
//     }
// };