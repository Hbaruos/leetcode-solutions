class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        func(0, nums, res, temp);
        return res;
    }
    
    void func(int i, vector<int> &nums, vector<vector<int>> &res, vector<int> &temp) {
        if (i == nums.size()) {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        func(i + 1, nums, res, temp);
        temp.pop_back();
        func(i + 1, nums, res, temp);
    }    
    
};
