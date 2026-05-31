class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int max_i = i;
        int max_j = j;
        int distance;
        int ans = 0;
        while (i < j){
            int min_h = min(heights[i], heights[j]);
            distance = j - i;
            int area = min_h * distance;
            ans = max(ans, area);

            /*Diện tích phụ thuộc vào cạnh nhỏ hơn, giữ nguyên cạnh nhỏ hơn không có khả năng làm tăng thể tích
            => thay đổi cạnh nhỏ hơn để có cơ hội tăng diện tích*/
            if (heights[i] < heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};
