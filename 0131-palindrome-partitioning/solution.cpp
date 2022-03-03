class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        func(0, s, res, temp);
        return res;
    }
    
    void func(int i, string s, vector<vector<string>> &res, vector<string> &temp) {
        if (i == s.size()) {
            res.push_back(temp);
            return;
        }
        for (int j = i; j < s.size(); ++j) {
            if (isPalindrome(i, s, j)) {
                temp.push_back(s.substr(i, j - i + 1));
                func(j + 1, s, res, temp);
                temp.pop_back();
            }
        }
    }
    
    bool isPalindrome(int i, string s, int j) {
        while (i <= j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};
