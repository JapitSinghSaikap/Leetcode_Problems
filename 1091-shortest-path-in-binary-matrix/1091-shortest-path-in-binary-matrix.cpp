class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return -1;

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(n, -1));
        //up down left right and saare diagonals 
        int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

        q.push({0,0});
        dist[0][0] = 1;

        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            //if reached the destination (n-1,y-1)
            if (x == n-1 && y == n-1) return dist[x][y];
            
            //saare dir explore krne hai
            for (auto& d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    grid[nx][ny] == 0 && dist[nx][ny] == -1) 
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return -1;
    }
};