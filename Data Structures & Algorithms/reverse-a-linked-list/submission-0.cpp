/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur->next != nullptr){
            ListNode *tmp = prev;
            prev = cur;
            cur = cur->next;
            prev->next = tmp;
        }
        cur->next = prev;
        head = cur;
        return head;
    }
};
