class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        func(0, nums, res, temp);
        return res;
    }
    
    void func(int i, vector<int> &nums, vector<vector<int>> &res, vector<int> &temp) {
        res.push_back(temp);
        
        for (int j = i; j < nums.size(); ++j) {
            if (j > i && nums[j] == nums[j - 1]) continue;
            temp.push_back(nums[j]);
            func(j + 1, nums, res, temp);
            temp.pop_back();
        }
    }
    
};
