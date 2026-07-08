class Solution {
  public int longestConsecutive(int[] nums) {
    // Convert array to Set for O(1) lookups
    Set<Integer> set = new HashSet<>();
    for (int num : nums)
      set.add(num);

    int longestStreak = 0;

    for (int num : set) {
      // Only process if 'num' is the absolute start of a sequence
      if (!set.contains(num - 1)) {
        int currentNum = num;
        int currentStreak = 1;

        // Count the length of the continuous sequence
        while (set.contains(currentNum + 1)) {
          ++currentNum;
          ++currentStreak;
        }

        longestStreak = Math.max(longestStreak, currentStreak);
      }
    }

    return longestStreak;
  }
}
