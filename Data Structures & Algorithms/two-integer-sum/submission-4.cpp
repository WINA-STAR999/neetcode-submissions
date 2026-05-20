
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mp;
        int size_nums = nums.size();
        for (int i = 0; i < size_nums; i++){
            int y = target - nums[i];
            if(mp.find(y) != mp.end()){
                return {mp[y], i};
            }
            mp[nums[i]] = i;
            }
    }
};