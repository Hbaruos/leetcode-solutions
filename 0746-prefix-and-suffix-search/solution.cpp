class WordFilter {
    private:
        std::unordered_map<std::string, int> um;
    public:
        WordFilter(std::vector<std::string> &words) {
            for (int i = 0; i < size(words); ++i) {
                std::string s1;
                for (int j = 0; j < size(words[i]); ++j) {
                    s1 += words[i][j];
                    std::string s2;
                    for (int k = size(words[i]) - 1; k >= 0; --k) {
                        s2 = words[i][k] + s2;
                        um[s1 + "-" + s2] = i + 1;
                    }
                }
            }
        }

        int f(std::string prefix, std::string suffix) {
            return um[prefix + "-" + suffix] - 1;
        }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
