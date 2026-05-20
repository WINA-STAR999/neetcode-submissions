class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int Size = nums.size();
        for (int i = 0; i < Size; i++){
            for (int j = i + 1; j < Size; j++){
                if (nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
    }
};