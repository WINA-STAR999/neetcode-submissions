class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int sum = 0;
    while (left < right){
        if (height[right] < height[left]){
            if (rightMax <= height[right]){
                rightMax = height[right];
            }
            else{
                sum += rightMax - height[right];
            }
            right--;
        }
        else{
            if (leftMax <= height[left]){
                leftMax = height[left];
            }
            else{
                sum += leftMax - height[left];
            }
            left++;
        }
    }
        return sum;
    }
};
