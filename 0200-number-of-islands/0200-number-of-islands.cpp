// class Solution {
// public:
//     int r,c;
//     bool valid(int i,int j){
//         return i>=0 && i<r && j>=0 && j<c;
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         r = grid.size();
//         c = grid[0].size();
//         int row[4] = {1, -1, 0, 0};
//         int col[4] = {0, 0, 1, -1};
//         queue<pair<int,int>> q;
//         int count = 0;
//         for(int i=0;i<r;i++){
//             for(int j=0;j<c;j++){
//                 if(grid[i][j] == '1'){
//                     count++;
//                     q.push({i,j});
//                     grid[i][j] = '0';//mark that spot as water taki count nhi kre wapis
//                     while(!q.empty()){
//                         int new_r = q.front().first;
//                         int new_c = q.front().second;
//                         q.pop();
//                         for(int k=0;k<4;k++){
//                             if(valid(new_r+row[k],new_c+col[k]) && grid[new_r+row[k]][new_c+col[k]] == '1'){
//                                 grid[new_r+row[k]][new_c+col[k]] = '0';
//                                 q.push({new_r+row[k],new_c+col[k]});
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };


class Solution {
public:
    int r, c;

    bool valid(int i, int j){
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    void dfs(int i, int j, vector<vector<char>>& grid){
        // mark visited
        grid[i][j] = '0';

        int row[4] = {1, -1, 0, 0};
        int col[4] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++){
            int ni = i + row[k];
            int nj = j + col[k];

            if(valid(ni, nj) && grid[ni][nj] == '1'){
                dfs(ni, nj, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();

        int count = 0;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i, j, grid); 
                }
            }
        }

        return count;
    }
};