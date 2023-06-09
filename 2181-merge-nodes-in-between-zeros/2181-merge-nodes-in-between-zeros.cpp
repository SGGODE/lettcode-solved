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
        int sum=0;
        vector<int>res;
        ListNode* temp=head;
        temp=temp->next;
        while(temp!=NULL){
            if(temp->val!=0){
                sum+=temp->val;
            }else{
                res.push_back(sum);
                sum=0;
            }
            temp=temp->next;
        }
        if(res.empty())return NULL;
        head=new ListNode(res[0]);
        temp=head;
        for(int i=1;i<res.size();i++){
            temp->next=new ListNode(res[i]);
            temp=temp->next;
        }
        return head;
    }
};