class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack <pair<int, double>> st;
        int result = 0;
        vector <pair<int, double>> v;
        for (int i = 0; i < position.size(); i++){
            pair <int, double> p = {position[i],(double)(target - position[i]) / speed[i]};
            v.push_back(p);
        }
        sort(v.rbegin(), v.rend());
        for (pair <int, double> tmp : v){
            while (!st.empty() &&  tmp.second > st.top().second){
                st.pop();
            }
            if (st.empty()){
                result++;
            }
            st.push(tmp);
        }
        return result;
    }
};
