class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int start = 0;
        int tank = 0;
        int total_cost = 0;
        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            tank += diff;
            if (tank < 0) {
            start = i + 1;
            tank = 0;
            }
            total_cost += diff;
        }
        return total_cost >= 0 ? start : -1;
    }
};
