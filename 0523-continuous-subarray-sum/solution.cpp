class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = sum % k;
            
            if (s.count(mod)) return true;
                s.insert(ans);
                ans = mod;
        }
        return false;
    }
};
