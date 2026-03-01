class Solution {
  public int concatenatedBinary(int n) {
    final int MOD = 1000000007;
    long result = 0;
    for (int i = 1; i <= n; i++) {
      int bits = 32 - Integer.numberOfLeadingZeros(i);
      result = (result * (1L << bits) % MOD + i) % MOD;
    }
    return (int) result;
  }
}

