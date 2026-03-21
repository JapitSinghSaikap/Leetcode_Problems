class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>>newone;
        for(int i=x+k-1;i<grid.size()&&i>=x;i--){
            vector<int>temp;
            for(int j=y;j<grid[i].size()&&j<y+k;j++){
                temp.push_back(grid[i][j]);
            }
            newone.push_back(temp);
        }
        int idx=0;
        for(int i=x;i<grid.size()&&i<x+k;i++){
            int l=0;
            for(int j=y;j<grid[i].size()&&j<y+k;j++){
                grid[i][j]=newone[idx][l];
                l++;
            }
            idx++;
        }
        return grid;
    }
};