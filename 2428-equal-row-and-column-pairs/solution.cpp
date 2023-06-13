class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
      int n = grid.size();
      int count = 0;
      map<vector<int>, int> row;

      for (auto &it: grid)
        ++row[it];

      for (int i = 0; i < n; ++i) {
        vector<int> col;

        for (int j = 0; j < n; ++j)
          col.emplace_back(grid[j][i]);

        count += row[col];
      }
      return count;
    }
};
