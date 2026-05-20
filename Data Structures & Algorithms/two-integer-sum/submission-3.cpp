class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set <int> us;
        for (auto it1 : nums){
            us.insert(it1);
        }
        for (int i = 0; i <= nums.size(); i++){
            if (us.find(target - nums[i]) != us.end()){
                for (int j = i + 1; j < nums.size(); j++){
                    if (nums[i] + nums[j] == target){
                        return {i, j};
                    }
                }
            }
        }
    }
};
