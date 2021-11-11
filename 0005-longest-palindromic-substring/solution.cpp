class Solution {
    public:
        std::string longestPalindrome(std::string s) {
            std::string x = "";
            int l = 0;
            x += s[0];
            if(s.empty()) return "";
            if(s.size() == 1) return s;

            for(int i=0; i<s.size(); ++i) {
                int i1 = i, i2 = i + 1;
                while(i1 >= 0 && i2 < s.size()) {
                    if(s[i1] == s[i2]) {
                        int len = i2 - i1 + 1;
                        if(len > l) {
                            l = len;
                            x = s.substr(i1, len);
                        }
                    }
                    else 
                        break;
                    i1--;
                    i2++;
                    
                }
            }
            
            for(int i=0; i<s.size(); ++i) {
                    int i1 = i - 1, i2 = i + 1;
                    while(i1 >= 0 && i2 < s.size()) {
                        if(s[i1] == s[i2]) {
                            int len = i2 - i1 + 1;
                            if(len > l) {
                                l = len;
                                x = s.substr(i1, len);
                            }
                        }
                        else 
                            break;
                        i1--;
                        i2++;
                    }
            }
            return x;
        }
};
