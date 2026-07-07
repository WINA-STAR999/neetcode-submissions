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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector <int> nodes;
        for (ListNode* lst : lists){
            while (lst){
                nodes.push_back(lst->val);
                lst = lst->next;
            }
        }
        sort(nodes.begin(), nodes.end());
        ListNode *result = new ListNode(0);
        ListNode *cur = result;
        for (int x : nodes){
            cur->next = new ListNode(x);
            cur = cur->next;
        }
        return result->next;
    }
};
