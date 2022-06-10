class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int i = 0, j = 0;
        int _max = 0;
        
        while (i < s.size()) {
            if (us.count(s[i]) == 0) {
                us.emplace(s[i]);
                i++;
                _max = max(_max, i-j);
            }
            else {
                us.erase(s[j]);
                j++;
            }
        }
        return _max;
    }
};
