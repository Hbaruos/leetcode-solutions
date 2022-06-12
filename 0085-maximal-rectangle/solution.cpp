class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1; 
                maxArea = max(maxArea, width * height);
            }     
            st.emplace(i);
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        vector<int> heights(matrix[0].size(), 0);
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') ++heights[j];
                else heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
