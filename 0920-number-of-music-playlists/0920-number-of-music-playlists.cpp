class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<long long>>dp;
    long long solve(int i , int j , int n , int k){

        if(i==0 && j==0){
            return 1;
        }
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long  res = 0;
        res = solve(i-1,j-1,n,k) * (n-(j-1))%mod;
        res = (res + solve(i-1,j,n,k) * (max(j-k,0)))%mod;
        return dp[i][j]=res;

    }
    int numMusicPlaylists(int n, int goal, int k) {
        dp.resize(101,vector<long long>(101,-1));
        return solve(goal,n,n,k);
    }
};