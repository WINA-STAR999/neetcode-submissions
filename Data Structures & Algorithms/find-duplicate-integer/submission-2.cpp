class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        coi như là:
        Node{
        slow  ==>(Node->data);
        nums  ==>[slow](Node->next)
        }
        */
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        slow = nums[0];
        while (slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
