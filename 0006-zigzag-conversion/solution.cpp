class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> v(numRows);
        int r = 0; 
        int inc = 1;
        for(int i=0; i<s.size(); ++i) {
            v[r] += s[i];
            if(r == 0) inc = 1;
            else if(r == numRows - 1) inc = -1;
            r += inc;
        }
        string ans;
        for(auto &i:v)
            ans += i;
        
        return ans;
    }
};
