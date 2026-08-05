class Solution {
  public int minDistance(String word1, String word2) {
    int m = word1.length();
    int n = word2.length();

    // Create a 2D DP table of size (m + 1) x (n + 1)
    int[][] dp = new int[m + 1][n + 1];

    // Initialize base cases
    for (int i = 0; i <= m; i++) {
      dp[i][0] = i; // Deleting all characters from word1 to match empty word2
    }
    for (int j = 0; j <= n; j++) {
      dp[0][j] = j; // Inserting all characters to empty word1 to match word2
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
          // Characters match, no operation needed
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          // Take the minimum of Delete, Insert, and Replace + 1
          int deleteOp = dp[i - 1][j];
          int insertOp = dp[i][j - 1];
          int replaceOp = dp[i - 1][j - 1];

          dp[i][j] = 1 + Math.min(deleteOp, Math.min(insertOp, replaceOp));
        }
      }
    }

    return dp[m][n];
  }
}
