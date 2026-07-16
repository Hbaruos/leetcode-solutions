class Solution {
  public int trap(int[] height) {
    if (height == null || height.length == 0) {
      return 0;
    }

    int left = 0;
    int right = height.length - 1;

    int leftMax = 0;
    int rightMax = 0;

    int totalWater = 0;

    while (left < right) {
      // Update the tallest walls seen so far from both directions
      leftMax = Math.max(leftMax, height[left]);
      rightMax = Math.max(rightMax, height[right]);

      // The smaller maximum wall dictates the water level constraint
      if (leftMax < rightMax) {
        // Water trapped is the difference between the max wall and current height
        totalWater += leftMax - height[left];
        left++;
      } else {
        totalWater += rightMax - height[right];
        right--;
      }
    }

    return totalWater;
  }
}
