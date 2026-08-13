class Solution {
  public int numDistinct(String s, String t) {
    int m = s.length();
    int n = t.length();

    // 2D DP table where dp[i][j] stores the count of distinct subsequences
    int[][] dp = new int[m + 1][n + 1];

    // Base case: empty t can be formed 1 way (by deleting everything)
    for (int i = 0; i <= m; i++) {
      dp[i][0] = 1;
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s.charAt(i - 1) == t.charAt(j - 1)) {
          // Include the match + exclude the match
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        } else {
          // Characters don't match, carry over previous count from s
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[m][n];
  }
}
