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
private:
    int length(ListNode* head){
        int cnt=0;
        if(head==NULL){
            return 0;
        }
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=head;
        int x=length(head);
        if(x%2==0){
        while(fast->next->next){
            //if(slow!=head) prev=prev->next;
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        }else{
             x=(int)x/2 -1;
            while(x--){
                slow=slow->next;
            }
        slow->next=slow->next->next;
        }
        return head;
    }
};