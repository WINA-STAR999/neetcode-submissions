class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0; int j = 0;
        vector <int> nums;
        while (i < nums1.size() && j < nums2.size()){
            if (nums1[i] < nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()){
            nums.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()){
            nums.push_back(nums2[j]);
            j++;
        }
        int m = nums.size() / 2;
        if (nums.size() % 2 == 0){
            return (nums[m - 1] + nums[m]) / 2.0;
        }
        else{
            return nums[m];
        }
    }
};
