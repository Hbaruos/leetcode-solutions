class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) 
            sum += nums[i];
        
        
        if (sum%2) return false;
        vector<vector<int>> dp(nums.size(), vector<int> (sum/2 + 1, 0));
        // return f(nums.size(), nums, sum/2, dp);
        for (int i = 0; i < nums.size(); ++i) dp[i][0] = true;
        if (nums[0] <= sum/2) dp[0][nums[0]] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 1; j < sum/2 + 1; ++j) {
                bool pick = false;
                if (j >= nums[i]) pick = dp[i - 1][j - nums[i]];
                bool n_Pick = dp[i - 1][j];
                dp[i][j] = pick | n_Pick;
            }
        }
        return dp[nums.size() - 1][sum/2];
    }
    
    // recursive approach
    
    // bool f(int i, vector<int> &n, int tar, vector<vector<int>> &dp) {
    //     if (tar == 0) return true;
    //     if (i == 0) return (n[0] == tar);
    //     if (dp[i][tar]) return dp[i][tar];
    //     bool pick = false;
    //     if (tar >= n[i]) pick = f(i - 1, n, tar - n[i], dp);
    //     bool n_Pick = f(i - 1, n, tar, dp);
    //     return dp[i][tar] = pick | n_Pick;
    // }
    
    
    // space optimization
    
    // bool f(int n, vector<int> &arr, int k) {
    // vector<bool> prev(k + 1, 0), cur(k + 1, 0);
    // prev[0] = cur[0] = true;
    // if (arr[0] <= k) prev[arr[0]] = true;
    // for (int i = 1; i < n; ++i) {
    //     for (int j = 1; j < k + 1; ++j) {
    //         bool n_Pick = prev[j];
    //         bool pick = false;
    //         if (arr[i] <= j) pick = prev[j - arr[i]];
    //         cur[j] = pick | n_Pick;
    //     }
    //     prev = cur;
    // }
    // return prev[k];
// }
    
};
