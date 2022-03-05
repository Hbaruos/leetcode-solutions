class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        func(board);
    }
    
    bool func(vector<vector<char>> &b) {
        for (int i = 0; i < b.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                if (b[i][j] == '.') {
                    for (char k = '1'; k <= '9'; ++k) {
                        if (isValid(b, k, i, j)) {
                            b[i][j] = k;
                            
                            if (func(b)) return true;
                            else b[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>> &b, char k, int row, int col) {
        for (int i = 0; i < b.size(); ++i) {
            if (b[i][col] == k)
                return false;
            
            if (b[row][i] == k)
                return false;
            
            if (b[3 * (row/3) + i/3][3 * (col/3) + i % 3] == k)
                return false;
        }
        return true;
    }    
    
};
