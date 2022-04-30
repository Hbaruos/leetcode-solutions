const static auto fast=[]{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define psd pair<string,double>
#define vd vector<double>

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<psd>> mp;
        for (int i=0; i<values.size(); i++){
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        vd ans;
        for (const auto &que : queries){
            if (!mp.count(que[0]) || !mp.count(que[1])) {
                ans.push_back(-1.0);
                continue;
            }
            if (que[0]==que[1]) {
                ans.push_back(1.0);
                continue;
            }
            queue<psd> q;
            unordered_set<string> seen;
            q.push({que[0],1.0});
            double res = -1.0;
            seen.insert(que[0]);
            while(q.size()){
                string curr;
                double val;
                tie(curr, val) = q.front();
                q.pop();
                if (curr == que[1]){
                    res = val;
                    break;
                }
                for (const auto &p: mp[curr]){
                    if (!seen.count(p.first)){
                        q.push({p.first, val*p.second});
                        seen.insert(p.first);
                    }
                }
                
            }
            ans.push_back(res);
        }
        return ans;
    }
};
