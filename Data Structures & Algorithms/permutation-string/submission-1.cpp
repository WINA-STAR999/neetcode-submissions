class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort (s1.begin(), s1.end());
        for (int i = 0; i < s2.size(); i++){
            if (i + s1.size() > s2.size()) break;
            string subString = s2.substr(i, s1.size());
            sort(subString.begin(), subString.end());
            if (s1 == subString) return true;
        }
        return false;
    }
};
