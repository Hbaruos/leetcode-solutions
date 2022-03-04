class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> res;
        for (int i = 1; i < n; ++i) {
            fact *= i;
            res.push_back(i);
        }
        res.push_back(n);
        string ans = "";
        k--;
        while (true) {
            ans = ans + to_string(res[k/fact]);
            res.erase(res.begin() + k/fact);
            if (res.size() == 0) break;
            k %= fact;
            fact /= res.size();
        }
        return ans;
    }
};
