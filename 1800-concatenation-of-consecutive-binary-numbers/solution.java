class Solution {
  public int concatenatedBinary(int n) {
    long MOD = 1_000_000_007;
    long result = 0;
    int bitLength = 0;

    for (int i = 1; i <= n; i++) {
      // If 'i' is a power of 2, it requires a brand new bit slot
      // Example: 2 (10), 4 (100), 8 (1000)
      if ((i & (i - 1)) == 0) {
        bitLength++;
      }

      // 1. Shift current result left to open up empty rooms for the new bits
      // 2. Add the bits of 'i' using bitwise OR
      // 3. Apply modulo to prevent overflowing
      result = ((result << bitLength) | i) % MOD;
    }

    return (int) result;
  }
}
