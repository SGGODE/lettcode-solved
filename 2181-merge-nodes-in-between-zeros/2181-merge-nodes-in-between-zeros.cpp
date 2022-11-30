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
       ListNode* temp=head;
       int cnt=0;
       temp=temp->next;
        vector<int>v;
        // while(temp!=NULL){
        //     v.push_back(temp->val);
        //     temp=temp->next;
        // }
        while(temp!=NULL){
            if(temp->val==0){
                v.push_back(cnt);
                cnt=0;
                //temp=temp->next;
            }
            cnt+=temp->val;
            temp=temp->next;
        }
        ListNode* dump=new ListNode(v[0]);
        head=dump;
        for(int i=1;i<v.size();i++){
           dump->next=new ListNode(v[i]);
           dump=dump->next;
        }
        return head;
    }
};