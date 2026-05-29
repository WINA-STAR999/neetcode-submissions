class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> result;
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end){
            int sum = numbers[start] + numbers[end];
            if (sum < target){
                start++;
            }
            else if(sum > target){
                end--;
            }
            else{
                result.push_back(start + 1);
                result.push_back(end + 1);
                return result;
            }
        }
        return result;
    }
};
