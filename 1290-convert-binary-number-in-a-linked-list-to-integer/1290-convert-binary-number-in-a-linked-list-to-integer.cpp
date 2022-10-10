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
    int sum=0,cnt=0;
    void deci(ListNode*head){
        if(head->next==NULL){
            return;
        }
        deci(head->next);
        ++cnt;
        sum=sum+((head->val)*(pow(2,cnt)));
    }
public:
    int getDecimalValue(ListNode* head) {
       // deci(head);
        //return sum;
        int ans=0;
        ListNode* temp=head;
        while(temp!=NULL){
            ans*=2;
            ans+=temp->val;
            temp=temp->next;
        }
        return ans;
    }
};