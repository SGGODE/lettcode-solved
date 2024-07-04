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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* runner = NULL;
        ListNode* newHead;
        bool flag = 1;
        ListNode* temp = head->next;
        int sum = 0;
        while(temp!=NULL){
            if(temp->val==0){
                if(!flag){
                    runner->next = new ListNode(sum);
                    runner = runner->next;
                }else{
                    runner = new ListNode(sum);
                    newHead = runner;
                    flag=0;
                }
                sum = 0;
            }else sum += temp->val;
            
            temp = temp->next;
        }
        return newHead;
    }
};