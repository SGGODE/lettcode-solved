/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* ch(ListNode* head){
         ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        while(fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                //break;
                 while(temp!=slow){
                   temp=temp->next;
                    slow=slow->next;
                   }
                return temp;
            }
        }
     // ListNode* temp=head;
    return NULL;
    // return slow;
    }
public:
    ListNode *detectCycle(ListNode *head) {
    if(head==NULL||head->next==NULL) return NULL;
         ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                 while(temp!=slow){
                   temp=temp->next;
                    slow=slow->next;
                   }
                return temp;
            }
        }
     // ListNode* temp=head;
    return NULL;
    }
};