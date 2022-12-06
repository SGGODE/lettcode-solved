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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp=head;
        vector<int>v;
        while(temp!=NULL){
         v.push_back(temp->val);
         temp=temp->next;
        }
        vector<int>x;int n=v.size();
        for(int i=0;i<n;i++){
            if(i%2!=0){
                x.push_back(v[i]);
                v[i]=INT_MAX;
            }
        }
        //for(auto it:v)cout<<it<<" ";cout<<endl;
        //for(auto it:x)cout<<it<<" ";cout<<endl;
        ListNode* result=new ListNode(-1);
        head=result;
        for(int i=0;i<n;i++){
            if(v[i]!=INT_MAX){
               result->next=new ListNode(v[i]);
               result=result->next;
            }
        }n=x.size();
        for(int i=0;i<n;i++){
            result->next=new ListNode(x[i]);
            result=result->next;
        }
        return head->next;
    }
};