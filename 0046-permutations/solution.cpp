class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        func(0, nums, res);
        return res;
    }
    
    void func(int k, vector<int> &nums, vector<vector<int>> &res) {
        if (k == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int i = k; i < nums.size(); ++i) {
            swap(nums[i], nums[k]);
            func(k + 1, nums, res);
            swap(nums[i], nums[k]);
        }
    }
    
};
