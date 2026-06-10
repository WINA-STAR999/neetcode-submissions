class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int result = 0;
        vector <pair<int, double>> v;
        for (int i = 0; i < position.size(); i++){
            pair <int, double> p = {position[i],(double)(target - position[i]) / speed[i]};
            v.push_back(p);
        }
        sort(v.rbegin(), v.rend());

        double maxTime = 0;
        for (pair <int, double> tmp : v){
            if (tmp.second > maxTime){
                result++;
                maxTime = tmp.second;
            }
        }
        return result;
    }
};
