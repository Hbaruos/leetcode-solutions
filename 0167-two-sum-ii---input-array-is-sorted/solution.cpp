class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m;
        vector<int> temp;
        for (int i = 0; i < numbers.size(); ++i) {
            if (m.find(target - numbers[i]) != m.end()) {
                temp.emplace_back(m[target - numbers[i]]);
                temp.emplace_back(i + 1);
            }
            m[numbers[i]] = i + 1;
        }
        return temp;
    }
};
