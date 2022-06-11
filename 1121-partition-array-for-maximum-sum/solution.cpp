class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
                
        for (int i = n - 1; i >= 0; --i) {
            
            int maxElement = INT_MIN;
            int _maxSum = INT_MIN;

            for (int j = i; j < min(n, i + k); ++j) {

                maxElement = max(maxElement, arr[j]);
                int sum = maxElement * (j - i + 1) + dp[j + 1];
                _maxSum = max(_maxSum, sum);

            }

           dp[i] = _maxSum; 
            
        }
        
        return dp[0];
    }
};
