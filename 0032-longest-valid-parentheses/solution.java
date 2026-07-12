class Solution {
    public int longestValidParentheses(String s) {
        if (s == null || s.length() < 2) {
            return 0;
        }

        int left = 0;
        int right = 0;
        int maxLength = 0;

        // Pass 1: Left-to-Right Scan
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(') {
                left++;
            } else {
                right++;
            }

            // Balanced pair found
            if (left == right) {
                maxLength = Math.max(maxLength, left + right);
            } 
            // Too many closing brackets -> sequence completely broken
            else if (right > left) {
                left = 0;
                right = 0;
            }
        }

        // Reset tracking variables for the reverse pass
        left = 0;
        right = 0;

        // Pass 2: Right-to-Left Scan (catches hanging opening brackets)
        for (int i = s.length() - 1; i >= 0; i--) {
            char ch = s.charAt(i);
            if (ch == '(') {
                left++;
            } else {
                right++;
            }

            // Balanced pair found
            if (left == right) {
                maxLength = Math.max(maxLength, left + right);
            } 
            // Too many opening brackets -> sequence completely broken
            else if (left > right) {
                left = 0;
                right = 0;
            }
        }

        return maxLength;
    }
}
