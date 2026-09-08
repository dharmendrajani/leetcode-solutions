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
    ListNode* partition(ListNode* head, int x) {

        if(head == NULL ){
            return head;
        }
        ListNode* h1 = NULL;
        ListNode* t1 = NULL;
        ListNode* h2 = NULL;
        ListNode* t2 = NULL;
        ListNode* temp = head;

        while(temp != NULL){
            ListNode* next = temp->next;
            temp->next = NULL;

            if(temp->val < x){
                if(h1 == NULL) {
                h1 = temp;
                t1 = temp;
                }else{
                t1->next = temp;
                t1 = temp;
                }

            }else{
                if(h2 == NULL) {
                h2 = temp;
                t2 = temp;
                }else{ 
                t2->next = temp;
                t2 = temp;
                }
            }
            temp = next;
        }
        if(h1 == NULL){
            return h2;
        }
        t1->next = h2;
        return h1;
    }
};