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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* t = list1;
        int cnt = 1;
        ListNode* head = t;
        while(cnt!=a){
            t = t->next;
            ++cnt;
        }
        ListNode* mid = t->next;
        t->next = NULL;
        t->next = list2;
        while(t->next!=NULL)t = t -> next;
        while(cnt!=b+1&&mid!=NULL){
            mid = mid->next;
            ++cnt;
        }
        if(mid!=NULL)t->next = mid;
        return head;
    }
};