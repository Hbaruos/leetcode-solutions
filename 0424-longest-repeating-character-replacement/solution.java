class Solution {
  public int characterReplacement(String s, int k) {
    int[] counts = new int[26];

    int left = 0;
    int maxFreq = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); ++right) {
      char currentRightChar = s.charAt(right);
      ++counts[currentRightChar - 'A'];

      maxFreq = Math.max(maxFreq, counts[currentRightChar - 'A']);

      int windowLength = right - left + 1;

      if (windowLength - maxFreq > k) {
        --counts[s.charAt(left) - 'A'];
        ++left;
      }
      maxLength = Math.max(maxLength, right - left + 1);
    }

    return maxLength;
  }
}
