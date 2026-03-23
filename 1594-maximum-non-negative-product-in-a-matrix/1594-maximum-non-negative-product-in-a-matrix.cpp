// class Solution {
// public:
//     int maxProductPath(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         const long long MOD = 1e9 + 7;

//         vector<vector<long long>> maxProd(m, vector<long long>(n));
//         vector<vector<long long>> minProd(m, vector<long long>(n));

//         maxProd[0][0] = minProd[0][0] = grid[0][0];

//         for (int i = 1; i < m; i++) {
//             maxProd[i][0] = minProd[i][0] = maxProd[i - 1][0] * grid[i][0];
//         }

//         for (int j = 1; j < n; j++) {
//             maxProd[0][j] = minProd[0][j] = maxProd[0][j - 1] * grid[0][j];
//         }

//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 long val = grid[i][j];

//                 long a = maxProd[i-1][j] * val;
//                 long b = minProd[i-1][j] * val;
//                 long c = maxProd[i][j-1] * val;
//                 long d = minProd[i][j-1] * val;

//                 maxProd[i][j] = max({a,b,c,d});
//                 minProd[i][j] = min({a,b,c,d});
//             }
//         }

//         long ans = maxProd[m-1][n-1];
//         if(ans < 0) return -1;
//         return ans % MOD;
//     }
// };

class Solution {
public:
    const long long MOD = 1e9 + 7;
    int m, n;

    vector<vector<pair<long long, long long>>> dp;
    vector<vector<bool>> vis;

    pair<long long, long long> solve(int i, int j, vector<vector<int>>& grid) {
        if (i == 0 && j == 0) {
            return {grid[0][0], grid[0][0]};
        }

        if (vis[i][j]) return dp[i][j];

        long long maxi = LLONG_MIN, mini = LLONG_MAX;

        if (i > 0) {
            auto [mx, mn] = solve(i - 1, j, grid);
            long long a = mx * grid[i][j];
            long long b = mn * grid[i][j];
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        if (j > 0) {
            auto [mx, mn] = solve(i, j - 1, grid);
            long long a = mx * grid[i][j];
            long long b = mn * grid[i][j];
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        vis[i][j] = true;
        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.resize(m, vector<pair<long long,long long>>(n));
        vis.resize(m, vector<bool>(n, false));

        auto [maxi, mini] = solve(m - 1, n - 1, grid);

        if (maxi < 0) return -1;
        return maxi % MOD;
    }
};