class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int , int> mp;
        for (auto x : nums){
            mp[x]++;
        }
        vector <vector<int>> freq (nums.size() + 1);
        for (auto [e, f] : mp){
            freq[f].push_back(e);
        }
        vector <int> result;
        for (int i = freq.size() - 1; i > 0; i--){
            for (int p : freq[i]){
                result.push_back(p);
                if (result.size() >= k){
                    return result;
                }
            }
        }
        return result;
    }   
};