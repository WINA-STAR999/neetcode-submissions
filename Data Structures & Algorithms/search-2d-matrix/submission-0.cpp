class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int top_row = 0;
       int bottom_row = matrix.size() - 1;
       int row_size = matrix.size() - 1;
       int colum_size = matrix[0].size() - 1;
       int row = -1;
       while (top_row <= bottom_row){
            int middle_row = top_row + (bottom_row - top_row) / 2;
            if (matrix[middle_row][0] <= target && matrix[middle_row][colum_size] >= target){
                row = middle_row;
                break;
            }
            else if(matrix[middle_row][0] > target){
                bottom_row = middle_row - 1;
            }
            else if (matrix[middle_row][0] < target){
                top_row = middle_row + 1;
            }
       }
       if (row == -1) return false;
       int left = 0;
       int right = colum_size;
       while (left <= right){
            int middle = left + (right - left) / 2;
            if (matrix[row][middle] == target){
                return true;
            }
            if (matrix[row][middle] > target){
                right = middle - 1;
            }
            else{
                left = middle + 1;
            }
       }
       return false;
    }
};
