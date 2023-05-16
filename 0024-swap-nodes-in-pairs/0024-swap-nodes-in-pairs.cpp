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
        int len=0;
        while(head!=NULL){
            ++len;
            head=head->next;
        }
        return len;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        int n=length(head);
        if(n==0)return NULL;
        ListNode* temp=head;
        while(temp->next!=NULL){
           int dump=temp->val; 
           temp->val=temp->next->val;
           temp->next->val=dump;
           if(temp->next->next==NULL)break;
           temp=temp->next;
           temp=temp->next;
        }
        return head;
    }
};