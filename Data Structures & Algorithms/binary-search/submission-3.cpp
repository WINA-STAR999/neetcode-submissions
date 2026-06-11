class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r){
            int m = (l + r) / 2;
            if (m == l){
                if (nums[m] == target){
                    return m;
                }
                break;
            }
            if (nums[m] > target){
                r = m;
                continue;
            }
            if (nums[m] < target){
                l = m;
                continue;
            }
            if (nums[m] == target){
                return m;
            }
        }
        return -1;
    }
};
