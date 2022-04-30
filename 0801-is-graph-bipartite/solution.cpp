class Solution {
public:
    
    bool bipartiteBfs(int src, vector<vector<int>> &g, int col[]) {
        queue<int> q;
        q.emplace(src);
        col[src] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto &it : g[node]) {
                if (col[it] == -1) {
                    col[it] = 1 - col[node];
                    q.emplace(it);
                } else if(col[it] == col[node]) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        int col[n];
        memset(col, -1, sizeof col);
        for (int i = 0; i < n; ++i) {
            if (col[i] == -1) {
                if (!bipartiteBfs(i, g, col)) return false;
            }
        }
        return true;
    }
};
