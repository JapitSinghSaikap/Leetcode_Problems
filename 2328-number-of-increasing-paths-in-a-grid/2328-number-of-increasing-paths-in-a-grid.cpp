class Solution {
public:
    const int MOD = 1e9+7;
        
    bool isSafe(int i , int j , vector<vector<int>>&grid , int el, int m , int n){
        if(i>=0 && j>=0 && i<m && j<n && grid[i][j]<el) return true;
        return false;
    }
    int solve(int i , int j , vector<vector<int>>&grid, int dx[], int dy[], int m , int n, vector<vector<int>>& dp){
        int res = 1;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=0;k<4;k++){
            int nrow = dx[k] + i;
            int ncol = dy[k] + j;
            //basicallly yhan pe out of bounds and ki aage wale element chota ho move krne se pehle
            if(isSafe(nrow,ncol,grid,grid[i][j],m,n)){
                res=(res + solve(nrow,ncol,grid,dx,dy,m,n,dp))%MOD;
            }
        }
        return dp[i][j]=res;
    }
    int countPaths(vector<vector<int>>& grid) {
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        int m = grid.size();
        int n = grid[0].size();
       vector<vector<int>> dp (m+1,vector<int>(n+1,-1));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans= (ans + solve(i,j,grid,dx,dy,m,n,dp))%MOD;
            }
        }
        return ans;

    }
};