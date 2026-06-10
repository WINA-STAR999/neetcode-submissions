class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <pair <int, int>> st;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++){
            int index = i;
            while (!st.empty() && heights[i] < st.top().second){
                pair <int, int> p = st.top();
                st.pop();
                int area = p.second * (i - p.first);
                index = p.first;
                if (area > maxArea){
                    maxArea = area;
                }
            }
            st.push({index, heights[i]});
        }
        while (!st.empty()){
            pair <int, int> p = st.top();
            st.pop();
            int area = p.second * (heights.size() - p.first);
            if (area > maxArea){
                maxArea = area;
            }
        }
        return maxArea;
    }
};
