class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> s(nums.begin(), nums.end());
        int max = 0;
        for (auto x : s){
            if (s.find(x - 1) == s.end()){
                int cnt = 1;
                int current = x;
                while (s.find(current + 1) != s.end()){
                    current++;
                    cnt++;
                }
                max = max > cnt ? max : cnt;
            }
        }
        return max;
    }
};
