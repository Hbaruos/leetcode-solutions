class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> hash(n), dp(n, 1);
        int maxi = 1;
        int lastIndex = 0;
        
        for (int i = 0; i < n; ++i) {
            hash[i] = i;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.emplace_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.emplace_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};
