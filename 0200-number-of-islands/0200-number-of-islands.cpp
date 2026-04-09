class Solution {
public:
    int r,c;
    bool valid(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int row[4] = {1, -1, 0, 0};
        int col[4] = {0, 0, 1, -1};
        queue<pair<int,int>> q;
        int count = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == '1'){
                    count++;
                    q.push(make_pair(i,j));
                    grid[i][j] = '0';
                    while(!q.empty()){
                        int new_r = q.front().first;
                        int new_c = q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            if(valid(new_r+row[k],new_c+col[k]) && grid[new_r+row[k]][new_c+col[k]] == '1'){
                                grid[new_r+row[k]][new_c+col[k]] = '0';
                                q.push(make_pair(new_r+row[k],new_c+col[k]));
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};