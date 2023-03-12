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
    ListNode* mergeKLists(vector<ListNode*>&lists) {
        priority_queue<int,vector<int>,greater<int>>q;
         int n=lists.size();
        if(lists.empty()) return NULL;
        for(int i=0;i<n;i++){
            ListNode* temp=lists[i];
            if(temp==NULL)continue;
            while(temp!=NULL){
                 q.push(temp->val);
                 temp=temp->next;
            }
        }
        if(q.empty())return NULL;
       ListNode* temp=new ListNode(q.top());
       ListNode* head=temp;
        q.pop();
        while(!q.empty()){
            temp->next=new ListNode(q.top());
            q.pop();
            temp=temp->next;
        }
        return head;
       // return head;
    }
};