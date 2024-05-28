class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (auto &num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int curNum = num;
                int curStreak = 1;

                while (numSet.find(curNum + 1) != numSet.end()) {
                    ++curNum;
                    ++curStreak;
                }
                longestStreak = max(longestStreak, curStreak);
            }
        }
        return longestStreak;
    }
};
