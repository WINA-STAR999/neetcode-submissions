class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map <char, int> mp;
        for (char tmp : s){
            if (mp.find(tmp) != mp.end()){
                mp[tmp]++;
            }
            else{
                mp.insert({tmp, 1});
            }
        }
        for (char c : t){
            if (mp.find(c) == mp.end() || mp[c] == 0) return false;
            else{
                mp[c]--;
            }
        }
        return true;
    }
};