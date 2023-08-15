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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)return NULL;
        vector<int>res;
        ListNode* temp=head;
        while(temp!=NULL){
            res.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>xres;
        for(int i=0;i<res.size();i++){
            if(res[i]<x)xres.push_back(res[i]);
        }
        for(int i=0;i<res.size();i++){
            if(res[i]>=x)xres.push_back(res[i]);
        }
        ListNode* result = new ListNode(xres[0]);
        ListNode* iterator = result;
        for(int i=1;i<xres.size();i++){
            iterator->next = new ListNode(xres[i]);
            iterator = iterator->next;
        }
        return result;
    }
};