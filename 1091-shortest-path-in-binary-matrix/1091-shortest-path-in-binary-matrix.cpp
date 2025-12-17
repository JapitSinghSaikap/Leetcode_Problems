class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();//row
        int m=grid[0].size();//col

        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;

        if (n==1 && m==1)
            return 1;

        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 1;

        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};


        q.push({1,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;

            q.pop();
            
            for(int i=0;i<8;i++){
                int newR=r+dr[i];
                int newC=c+dc[i];

                if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]==0 && dis+1<dist[newR][newC]){
                    dist[newR][newC]=1+dis;
                    if(newR==n-1 && newC==m-1) return 1+dis;
                    q.push({dis+1,{newR,newC}});
                }
            }
        }

        return -1;
    }
};


// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         if (grid[0][0] || grid[n-1][n-1]) return -1;

//         queue<pair<int,int>> q;
//         vector<vector<int>> dist(n, vector<int>(n, -1));
//         //up down left right and saare diagonals 
//         int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

//         q.push({0,0});
//         dist[0][0] = 1;

//         while (!q.empty()) {
//             auto [x,y] = q.front();
//             q.pop();
//             //if reached the destination (n-1,y-1)
//             if (x == n-1 && y == n-1) return dist[x][y];
            
//             //saare dir explore krne hai
//             for (auto& d : dir) {
//                 int nx = x + d[0];
//                 int ny = y + d[1];

//                 if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
//                     grid[nx][ny] == 0 && dist[nx][ny] == -1) 
//                 {
//                     dist[nx][ny] = dist[x][y] + 1;
//                     q.push({nx, ny});
//                 }
//             }
//         }
//         return -1;
//     }
// };