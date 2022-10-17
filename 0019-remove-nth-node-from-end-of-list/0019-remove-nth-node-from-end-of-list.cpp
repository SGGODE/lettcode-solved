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
    int len(ListNode* head){
    int l=1;
       while(head->next){
           head=head->next;
           l++;
       }
        return l;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(head==NULL||head->next==NULL)
           return NULL;
      int l=len(head);
      int x=l-n;
     if(n==1){
         ListNode* temp=head;
         while(temp->next->next){
             temp=temp->next;
         } 
         temp->next=NULL;
     }else{
          int cnt=0;
          ListNode* temp=head;
          while(cnt!=x&&temp->next){
              temp=temp->next;
              ++cnt;
          }
          temp->val=temp->next->val;
          temp->next=temp->next->next;
//       //}
//       else{
//           LIstNode* temp=head;
//           while(temp->next->next){
              
//           }
       }
        return head;
    }
};