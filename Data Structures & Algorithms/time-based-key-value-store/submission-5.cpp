class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map <string, vector <pair<int, string>>> mp;
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        int i = 0;
        int j = mp[key].size() - 1;
        string result = "";
        vector <pair<int, string>> arr = mp[key];
        while (i <= j){
            int m = i + (j - i) / 2;
            if (arr[m].first == timestamp){
                return arr[m].second;
            }
            if (arr[m].first > timestamp){
                j = m - 1;
            }
            else{
                i = m + 1;
                result = arr[m].second;
            }
        }
        return result;
    }

};
