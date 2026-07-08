class Solution {
  public int[] productExceptSelf(int[] nums) {
    int n = nums.length;
    int[] ans = new int[n];

    // Step 1: Calculate prefix products (going left-to-right)
    // 'ans[i]' will temporarily hold the product of all elements to the left of i.
    ans[0] = 1; // There are no elements to the left of index 0
    for (int i = 1; i < n; i++)
      ans[i] = ans[i - 1] * nums[i - 1];

    // Step 2: Calculate suffix products on the fly (going right-to-left)
    // 'rightProduct' tracks the running product of all elements to the right of i.
    int rightProduct = 1; // There are no elements to the right of the last index
    for (int i = n - 1; i >= 0; i--) {
      // Multiply the left product (already in ans[i]) by the right product
      ans[i] = ans[i] * rightProduct;

      // Update the running right product for the next element to the left
      rightProduct *= nums[i];
    }

    return ans;
  }
}
