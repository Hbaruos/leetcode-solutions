class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        
        for (int i = 0; i < size(heights) - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0)
                pq.emplace(-diff);
            
            if (size(pq) > ladders) {
                bricks += pq.top();
                pq.pop();
            }
            
            if (bricks < 0) return i;
        }
        return size(heights) - 1;
    }
};
