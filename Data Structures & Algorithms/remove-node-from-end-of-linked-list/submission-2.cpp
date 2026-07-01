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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        vector <ListNode*> nodes;
        ListNode *cur = head;
        while(cur){
            nodes.push_back(cur);
            cur = cur->next;
        }
        int index = nodes.size() - n;
        if (nodes[index] == head){
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        if (nodes[index] == nodes[nodes.size() - 1]){
            ListNode *tmp = nodes[index];
            nodes[index - 1]->next = nullptr;
            delete tmp;
            return head;
        }
        nodes[index - 1]->next = nodes[index + 1];
        delete nodes[index];
        return head;
    }
};
