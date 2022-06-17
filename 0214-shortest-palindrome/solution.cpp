class Solution {
public:
    vector<int> prefix_function(string &s) {
        vector<int> p(size(s), 0);
        
        for (int i = 1; i < size(s); ++i) {
            int j = p[i - 1];
            
            while (j > 0 && s[i] != s[j])
                j = p[j - 1];
            
            if (s[i] == s[j]) 
                ++j;
            
            p[i] = j;
        }
        return p;
    }

    string shortestPalindrome(string s) {
        if (size(s) < 1) return s;
        string rev_s = string(rbegin(s), rend(s));
        string str = s + "#" + rev_s;
        vector<int> prefix = prefix_function(str);

        return rev_s.substr(0, size(s) - prefix[size(str) - 1]) + s;
    }
};
