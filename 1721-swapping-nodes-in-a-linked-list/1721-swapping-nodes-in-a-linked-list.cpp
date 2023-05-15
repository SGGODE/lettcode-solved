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
        int k=0;
        while(head!=NULL){
            ++k;
            head=head->next;
        }
        return k;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n=length(head);
        int last=n-(k-1);
        ListNode* start=head;
        ListNode* end=head;
        int first=1;
        while(first!=k){
            ++first;
            start=start->next;
        }
        int second=1;
         while(second!=last){
            ++second;
            end=end->next;
        }
       int temp= start->val;
        start->val=end->val;
        end->val=temp;
        return head;
    }
};