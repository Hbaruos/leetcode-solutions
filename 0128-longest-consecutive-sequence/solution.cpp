class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> us;
        for (int i : nums)
            us.insert(i);

        nums.clear();
        for (int i : us)
            nums.push_back(i);
        int res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (us.find(nums[i] - 1) == us.end()) {
                int j = nums[i];

                while (us.find(j) != us.end())
                    j++;

                res = max(res, j - nums[i]);
            }
        }
        return res;
    }
};
