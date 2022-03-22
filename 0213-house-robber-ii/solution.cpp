class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        if (nums.size() == 1) return nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (i) temp1.push_back(nums[i]);
            if (i != nums.size() - 1) temp2.push_back(nums[i]);
        }
       return max(func(temp1), func(temp2));
    }
    
    int func(vector<int> &nums) {
        
        int prev2 = 0, prev = nums[0];
        
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
