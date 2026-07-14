import java.util.Arrays;

class Solution {
  private final int MOD = 1_000_000_007;

  public int subsequencePairCount(int[] nums) {
    int n = nums.length;

    // Find maximum value to establish safe boundary limits for our GCD states
    int maxVal = 0;
    for (int num : nums) {
      maxVal = Math.max(maxVal, num);
    }

    // mem[index][gcd_x][gcd_y]
    Integer[][][] mem = new Integer[n][maxVal + 1][maxVal + 1];

    return dp(0, 0, 0, nums, mem);
  }

  private int dp(int i, int x, int y, int[] nums, Integer[][][] mem) {
    // Base case: processed all numbers
    if (i == nums.length) {
      // Both must be non-empty (x > 0) and have identical GCD values
      return (x > 0 && x == y) ? 1 : 0;
    }

    // Return precalculated state if it exists
    if (mem[i][x][y] != null) {
      return mem[i][x][y];
    }

    // Choice 1: Skip the current number entirely
    long count = dp(i + 1, x, y, nums, mem);

    // Choice 2: Place the current number into the first subsequence
    count += dp(i + 1, gcd(x, nums[i]), y, nums, mem);

    // Choice 3: Place the current number into the second subsequence
    count += dp(i + 1, x, gcd(y, nums[i]), nums, mem);

    // Store bounded result to prevent storage overflows
    return mem[i][x][y] = (int) (count % MOD);
  }

  // Standard Euclidean algorithm for GCD calculation
  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
