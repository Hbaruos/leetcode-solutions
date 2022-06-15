class Solution {
public:
    int _totalNQueens(vector<bool> &leftRow, vector<bool> &upperDiagonal, 
                      vector<bool> &lowerDiagonal, int col) {
        int count = 0, n = leftRow.size();
        if (col == n) return 1; 
        
        for (int row = 0; row < n; ++row)
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 
                && upperDiagonal[n - 1 + col - row] == 0) {
                
                leftRow[row] = lowerDiagonal[row + col] 
                    = upperDiagonal[n - 1 + col - row] = true;
                
                count += _totalNQueens(leftRow, upperDiagonal,
                              lowerDiagonal, col + 1);

                leftRow[row] = lowerDiagonal[row + col]
                    = upperDiagonal[n - 1 + col - row] = false;
                
            }
        return count;
    }
    
    int totalNQueens(int n) {
        vector<bool> leftRow(n), upperDiagonal(2 * n - 1), lowerDiagonal(2 * n - 1);
        return _totalNQueens(leftRow, upperDiagonal, lowerDiagonal, 0);
    }
};
