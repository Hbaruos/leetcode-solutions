class Solution {
public:
    void _reverseString(vector<char> &s, int i, int j) {
        if (i < j) 
            swap(s[i],s[j]) , _reverseString(s, i + 1, j - 1);
        else return;
    }
    
    void reverseString(vector<char>& s) {
        _reverseString(s, 0, s.size() - 1);    
    }
};
