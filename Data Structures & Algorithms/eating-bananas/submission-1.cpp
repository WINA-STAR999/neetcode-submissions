class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_value = -1;
        for (int x : piles){
            if (max_value < x) max_value = x;
        }
        int l = 1, r = max_value;
        int ans = r;
        while (l <= r){
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (int i = 0; i < piles.size(); i++){
                cnt += (piles[i] + m - 1) / m;
            }
            if (cnt > h){
                l = m + 1;
            }
            else{
                ans = m;
                r = m - 1;
            }
        }
        return ans;
    }
};
