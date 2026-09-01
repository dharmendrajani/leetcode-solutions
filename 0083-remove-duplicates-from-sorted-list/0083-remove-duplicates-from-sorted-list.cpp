class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;

        ListNode* curr = head;

        while(curr->next != NULL) {
            if(curr->val != curr->next->val) {
                curr = curr->next;
            }
            else {
                ListNode* duplicate = curr->next;

                curr->next = curr->next->next;

                delete duplicate;
            }
        }

        return head;
    }
};