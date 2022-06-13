class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int sum = 0;
        
        for (int i = 1; i < matrix.size(); ++i)
            for (int j = 1; j < matrix[0].size(); ++j)
                if (matrix[i][j]) 
                    matrix[i][j] = 1 + min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
        
        
        for (auto &it : matrix)
            sum += accumulate(it.begin(), it.end(), 0);
        
        return sum;
    }
};
