class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> a;
        for (auto it : nums){
            if (a.count(it)) return true;
            else a.insert(it);
        }
        return false;
    }
};