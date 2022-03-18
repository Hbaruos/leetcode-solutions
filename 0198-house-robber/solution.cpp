class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int sum = nums[i];
            if (i > 1) sum += prev2;
            int _sum = prev;
        
            int cur = max(sum, _sum);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};
