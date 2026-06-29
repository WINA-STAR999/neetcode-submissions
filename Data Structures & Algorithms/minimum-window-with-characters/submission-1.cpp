class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        unordered_map <char, int> need;
        unordered_map <char, int> window;
        for (char c : t){
            need[c]++;
        }
        int needCount = need.size();
        int have = 0;
        int left = 0;
        int minW = INT_MAX;
        int start = 0;
        for (int right = 0; right < s.size(); right++){
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]){
                have++;
            }
            while (have == needCount){
                if (minW > (right - left + 1)){
                    minW = right - left + 1;
                    start = left;
                }
                window[s[left]]--;
                if (need.count(c) && window[s[left]] < need[s[left]]){
                    have--;
                }
                left++;
            }
        }
        if (minW == INT_MAX) return "";
        string result;
        while (minW){
            result += s[start];
            start++;
            minW--;
        }
        return result;
    }
};
