class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector <string>> mp;
        for (auto it : strs){
            int a[26] = {0};
            for (char c : it){
                a[c - 'a']++;
            }
            string key = "";
            for (int j = 0; j < 26; j++){
                key += '#' + a[j];
            }
            mp[key].push_back(it);
        }
        vector <vector<string>> v;
        for (auto i : mp){
            v.push_back(i.second);
        }
        return v;
    }
};