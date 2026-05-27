class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        //Nap vao Set => khi tim kiem dat O(1)
        unordered_set <int> s;
        for (int x : nums){
            s.insert(x);
        }
    while (!s.empty()){
        //Lay tung so trong s
        int tmp = *(s.begin());
        int cnt = 1;

        //Lan luot lay cac so hop le ra khoi s
        int a = tmp + 1;
        int b = tmp - 1;
        s.erase(tmp);
        while (s.find(a) != s.end()){
            cnt++;
            s.erase(a);
            a++;
        }
        while (s.find(b)!= s.end()){
            cnt++;
            s.erase(b);
            b--;
        }
        if (result < cnt){
            result = cnt;
        }
    }  
    return result;      
    }
};
