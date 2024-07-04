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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* cur = head->next;
        ListNode* prev = head;
        int sum = 0;
        while(cur != NULL){
            sum += cur->val;
            if(cur->val == 0) {cur->val = sum; sum = 0; prev->next = cur; prev=cur;}
            cur = cur->next;
        }
        return head->next;
    }
};
