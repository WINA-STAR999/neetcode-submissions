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
    ListNode *mergeTwoList(ListNode *list1, ListNode *list2){
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val <= list2->val){
            list1->next = mergeTwoList(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoList(list1, list2->next);
            return list2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        queue <ListNode*> q;
        for(int i = 0; i < lists.size(); i++){
            q.push(lists[i]);
        }
        while (q.size() > 1){
            ListNode *newList1 = q.front(); q.pop();
            ListNode *newList2 = q.front(); q.pop();
            ListNode *newList = mergeTwoList(newList1, newList2);
            q.push(newList);
        }
        return q.front();
    }
};
