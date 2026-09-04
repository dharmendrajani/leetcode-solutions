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
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast becomes NULL, remove the head
        if(fast == NULL) {
            return head->next;
        }

        // Move both until fast reaches the last node
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove slow->next
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};