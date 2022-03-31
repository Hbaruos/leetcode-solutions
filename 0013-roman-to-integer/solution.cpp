class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int num = 0;
        
        for (int i = 0; i < s.size() - 1; ++i) {
            if (m[s[i]] < m[s[i + 1]]) num -= m[s[i]];
            else num += m[s[i]];
        }
        num += m[s.back()];
        return num;
    }
};
