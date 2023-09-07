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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int>mp;
        ListNode* temp = head;
        while(temp!=NULL){
             mp[temp->val]++;
            temp = temp->next;
        }
        ListNode* newList = new ListNode(-1);
        temp = newList;
        for(auto&it:mp){
            if(it.second==1){
              temp->next = new ListNode(it.first);
              temp = temp->next;
            }
        }
        return newList->next;
    }
};