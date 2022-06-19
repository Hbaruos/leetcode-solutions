class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        std::vector<std::vector<std::string>> suggestedWords;
        sort(begin(products), end(products));

        for (int w = 1; w <= size(searchWord); ++w) {
            std::string word = searchWord.substr(0, w);
            int count = 0;
            std::vector<std::string> temp;

            for (int i = 0; i < size(products); ++i) {
                if (word == products[i].substr(0, w) && count < 3) {
                    ++count; 
                    temp.emplace_back(products[i]);
                }
            }
            suggestedWords.emplace_back(temp);
        }
        return suggestedWords;        
    } 
};
