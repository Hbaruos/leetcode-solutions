class Solution {
  public String minWindow(String s, String t) {
    if (s == null || t == null || s.length() < t.length()) {
      return "";
    }

    // Frequency array for characters we need from t
    int[] mapT = new int[128];
    int uniqueCharsT = 0;
    for (int i = 0; i < t.length(); i++) {
      if (mapT[t.charAt(i)] == 0)
        uniqueCharsT++;
      mapT[t.charAt(i)]++;
    }

    // Frequency array for our current sliding window
    int[] windowMap = new int[128];

    int have = 0;
    int need = uniqueCharsT;

    int minLen = Integer.MAX_VALUE;
    int minStart = 0;

    int left = 0;

    // Move the right pointer to expand the window
    for (int right = 0; right < s.length(); right++) {
      char rChar = s.charAt(right);
      windowMap[rChar]++;

      // If the character is required and we matched its exact target count
      if (mapT[rChar] > 0 && windowMap[rChar] == mapT[rChar]) {
        have++;
      }

      // Phase 2: Shrink the window from the left while it is fully valid
      while (have == need) {
        int currentWindowLen = right - left + 1;
        if (currentWindowLen < minLen) {
          minLen = currentWindowLen;
          minStart = left;
        }

        char lChar = s.charAt(left);
        windowMap[lChar]--;

        // If removing this character breaks our required count threshold
        if (mapT[lChar] > 0 && windowMap[lChar] < mapT[lChar]) {
          have--;
        }

        left++; // Shrink window
      }
    }

    return minLen == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLen);
  }
}
