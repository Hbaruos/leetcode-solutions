#include <iostream>
#include <algorithm>
#include <unordered_set>

class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
            std::unordered_set<int> us;
            int l = 0, i = 0, j=0;
            while(j<s.size()) {
                if(us.count(s[j]) > 0) {
                    us.erase(s[i]);
                    i++;
                }
                else {
                    us.insert(s[j]);
                    j++;
                    l = std::max(l, j-i);
                }
            }
            return l;
        }
};
