class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;
        for (auto &it : adj[node]) {
            if (!visited[it]) dfs(it, adj, visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int vertices = isConnected.size();
        
        vector<int> adj[vertices];
        
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }
        
        vector<bool> visited(vertices+1, false);
        int count = 0;
        
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                ++count;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};
