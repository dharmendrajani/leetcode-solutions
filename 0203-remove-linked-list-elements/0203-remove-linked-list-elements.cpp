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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }
        while(head->val == val){
            if(head->next != NULL){
            ListNode* itself = head;
            head = itself->next;
            delete itself;
            }else{
                return NULL;
            }
        }
        ListNode* temp = head;

        while(temp->next != NULL){
            if(temp->next->val == val){
                ListNode* curr = temp->next;
                temp->next = curr->next;
                // delete head
                delete curr;
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};