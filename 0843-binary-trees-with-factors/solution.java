class Solution {
  public int numFactoredBinaryTrees(int[] arr) {
    int MOD = 1_000_000_007;

    // Sort array to ensure we process smaller numbers first
    Arrays.sort(arr);

    // Map to store the number of trees with root as key
    Map<Integer, Long> dp = new HashMap<>();

    for (int i = 0; i < arr.length; i++) {
      // Base case: every element can form at least a single-node tree
      dp.put(arr[i], 1L);

      for (int j = 0; j < i; j++) {
        // Check if arr[j] is a factor of arr[i]
        if (arr[i] % arr[j] == 0) {
          int right = arr[i] / arr[j];

          // If the complementary factor exists, update dp[arr[i]]
          if (dp.containsKey(right)) {
            long ways = (dp.get(arr[j]) * dp.get(right)) % MOD;
            dp.put(arr[i], (dp.get(arr[i]) + ways) % MOD);
          }
        }
      }
    }

    // Sum up all tree counts from the map
    long totalTrees = 0;
    for (long count : dp.values()) {
      totalTrees = (totalTrees + count) % MOD;
    }

    return (int) totalTrees;
  }
}
