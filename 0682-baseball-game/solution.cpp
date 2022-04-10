class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int sum = 0;
        
        for (auto it : ops) {
            if (it == "C") s.pop();
            else if (it == "D") s.push(s.top() * 2);
            else if (it == "+") {
                int val = s.top(); s.pop();
                int val2 = s.top();
                s.push(val);
                s.push(val + val2);
            }
            else s.push(stoi(it));
        }
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};
