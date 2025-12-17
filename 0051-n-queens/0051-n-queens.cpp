class Solution {
public:
    vector<vector<string>>ans;
    bool isSafe(int row , int col , vector<string>&boards, int n){
        // top left -> i-1,j-1,
        int nrow = row;
        int ncol = col;
        while(nrow>=0 && ncol>=0){
            if(boards[nrow--][ncol--]=='Q') return false;
        }
        nrow = row;
        ncol = col;
        
        // left -> i,j-1
        while(ncol>=0){
            if(boards[row][ncol--]=='Q') return false;
        }
        nrow = row;
        ncol = col;

        // bottom left  -> i-1,j+1
        while(nrow<n && ncol>=0){
            if(boards[nrow++][ncol--]=='Q') return false;
        }
    
        return true;
    }

    void solve(int col , vector<string>&boards, int n){
        if(col==n){
            ans.push_back(boards);
            return;
        }
        for(int row = 0; row < n; row++){
            if(isSafe(row,col,boards,n)){
                boards[row][col]='Q';
                solve(col+1,boards,n);
                boards[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> boards(n, string(n, '.'));
        solve(0,boards,n);
        return ans;
    }

};