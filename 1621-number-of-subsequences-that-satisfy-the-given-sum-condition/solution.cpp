class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int res = 0, n = nums.size(), l = 0, r = n - 1, mod = 1e9 + 7;
        vector<int> pow(n, 1);
        
        for (int i = 1; i < n; ++i) 
            pow[i] = pow[i - 1] * 2 % mod;
        
        while (l <= r) {
            if (nums[l] + nums[r] > target) r--;
            else res = (res + pow[r - l++]) % mod;
        }
        return res;        
    }
};
