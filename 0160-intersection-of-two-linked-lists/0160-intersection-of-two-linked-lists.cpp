/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     map<ListNode*,int>mp;
    //     ListNode* temp=headA;
    //     while(temp!=NULL){
    //         mp[temp]++;
    //         temp=temp->next;
    //     }
    //     temp=headB;
    //     while(temp!=NULL){
    //         if(mp.find(temp)!=mp.end()){
    //             return temp;
    //         }
    //         mp[temp]++;
    //     }
    //     return NULL;
      ListNode* temp=headA;
      while(temp!=NULL){
            ListNode* another=headB;
            while(another!=NULL){
              if(another==temp){
                  return another;
              }
              another=another->next;
            }
          temp=temp->next;
      }
        return NULL;
    }
};