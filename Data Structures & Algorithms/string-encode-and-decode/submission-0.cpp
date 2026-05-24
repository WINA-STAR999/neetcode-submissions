class Solution {
public:
    string encode(vector<string>& strs) {
        string s_encode;
        for (string s : strs){
            int cnt = s.length();
            s_encode += "#" + to_string(cnt) + "#" + s;
        }
        return s_encode;
    }

    vector<string> decode(string s) {
        vector <string> s_decode;
        int i = 0;
        while (i < s.length()){
            while(s[i] != '#'){
                i++;
            }
            ++i;

            string len;
            while(s[i] != '#'){
                len += s[i++];
            }

            int cnt = stoi(len);
            ++i;

            string tmp;
            
            int k = 0;
            while (k < cnt){
                tmp += s[i++];
                k++;
            }
            s_decode.push_back(tmp);
        }
        return s_decode;
    }
};