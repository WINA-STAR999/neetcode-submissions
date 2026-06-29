class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, res = 0;
        int maxFreg = 0;
        unordered_map <char, int> mp;
        for (int right = 0; right < s.size(); right++){
            mp[s[right]]++;
            if (maxFreg < mp[s[right]]) maxFreg = mp[s[right]];
            if ((right - left + 1 - maxFreg) <= k){
                res = right - left + 1;
            }
            else{
                mp[s[left]]--;
                left++;
            }
        }
        return res;
    }
};
