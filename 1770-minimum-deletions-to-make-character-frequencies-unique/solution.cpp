class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int, int> chFreq;
        unordered_map<int, int> uniqueFreq;
        int cnt = 0;
        
        for (auto &it : s)
            chFreq[it]++;
        
        for (auto &it : chFreq) {
            int i = it.second;            
            if (uniqueFreq.count(i) > 0) {
                while (i > 0 && uniqueFreq.count(i) > 0)
                    --i, ++cnt;
            }
            
            if (i > 0) 
                uniqueFreq[i]++;
        }
        return cnt;
    }
};
