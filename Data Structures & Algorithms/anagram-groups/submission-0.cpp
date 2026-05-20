class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string tmp;
        unordered_map <string, vector<string>> mp;
        for (auto it : strs){
            tmp = it;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(it);
        }
        vector <vector<string>> vt;
        for (auto i : mp){
            vt.push_back(i.second);
        }
        return vt;
    }
};