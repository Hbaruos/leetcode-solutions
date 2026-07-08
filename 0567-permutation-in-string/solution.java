class Solution {
  public boolean checkInclusion(String s1, String s2) {
    int l1 = s1.length();
    int l2 = s2.length();

    if (l1 > l2)
      return false;

    int[] s1Count = new int[26];
    int[] s2Count = new int[26];

    for (int i = 0; i < l1; ++i) {
      ++s1Count[s1.charAt(i) - 'a'];
      ++s2Count[s2.charAt(i) - 'a'];
    }

    if (Arrays.equals(s1Count, s2Count))
      return true;

    for (int right = l1; right < l2; ++right) {
      ++s2Count[s2.charAt(right) - 'a'];

      int left = right - l1;
      --s2Count[s2.charAt(left) - 'a'];

      if (Arrays.equals(s1Count, s2Count))
        return true;
    }

    return false;
  }
}
