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
    ListNode* reverse(ListNode* head) {
        ListNode *tmp = NULL, *prev = NULL;
        while(head != NULL){
            tmp = head;
            head = head->next;
            tmp->next = prev;
            prev = tmp;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* cur = head;
        int remainder = ((cur->val)*2)%10;
        int carry = ((cur->val)*2)/10;
        ListNode* head2 = new ListNode(remainder);
        ListNode* cur2 = head2;
        cur = cur->next;
        while(cur != NULL){
            remainder = ((cur->val)*2)%10;
            cur2->next = new ListNode(carry + remainder);
            carry = ((cur->val)*2)/10;
            cur = cur->next;
            cur2 = cur2->next;   
        }
        if(carry) cur2->next = new ListNode(1);
        return reverse(head2);
    }
};
