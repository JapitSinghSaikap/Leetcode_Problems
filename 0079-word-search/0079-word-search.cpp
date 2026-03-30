class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int index,int i,int j){
        if(index == word.size()) return true;
        //out of bounds condition
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board,word,index+1,i+1,j) ||
                     dfs(board,word,index+1,i-1,j) ||
                     dfs(board,word,index+1,i,j+1) ||
                     dfs(board,word,index+1,i,j-1);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dfs(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
};