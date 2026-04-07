class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r=0;r<9;r++) {
            for (int c=0;c<9;c++) {
                if (arr[r][c]=='.') continue;

                int num = arr[r][c]-'1'; 
                int ind = (r/3)*3+(c/3);

                if (rows[r][num] || cols[c][num] || boxes[ind][num])
                    return false;

                rows[r][num] = cols[c][num] = boxes[ind][num] = true;
            }
        }
        return true;
    }
};