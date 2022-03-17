class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp = 0, sum = INT_MIN;
        for (auto it : nums) {
            temp = max(it, it + temp);
            sum = max(temp, sum);
        }
        return sum;
    }
};
