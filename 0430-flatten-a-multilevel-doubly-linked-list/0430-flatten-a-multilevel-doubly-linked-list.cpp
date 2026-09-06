/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) {return head;}

        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                Node* next1=curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                while(curr->next != NULL){
                    curr=curr->next;
                }    
                    if(next1!=NULL){
                        curr->next = next1;
                        next1->prev = curr;
                    }                
            }    
            curr= curr->next;
        }
        return head;
    }
};