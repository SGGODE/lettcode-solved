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
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
            return NULL;
        vector<int>v;
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        temp=NULL;
        sort(v.begin(),v.end());
       ListNode* temp1=new ListNode(v[0]);
        temp=temp1;
        for(int i=1;i<v.size();i++){
            ListNode* cot=new ListNode(v[i]);
            temp1->next=cot;
            temp1=temp1->next;
        }
        temp1->next=NULL;
        return temp;
    }
};