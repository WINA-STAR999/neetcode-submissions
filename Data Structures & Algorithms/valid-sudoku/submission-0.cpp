class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool column[9][9] = {false};
        bool v[3][3][9] = {false};
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] <= '9' && board[i][j] >= '1'){
                    int tmp = board[i][j] - '1';
                    if (row[i][tmp] != false || column[j][tmp] != false || v[i/3][j/3][tmp] != false){
                        return false;
                    }
                    else{
                        row[i][tmp] = true; column[j][tmp] = true; v[i/3][j/3][tmp] = true;
                    }
                }
            }
        }
        return true;
    }
};