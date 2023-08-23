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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>res;
        ListNode* temp=head;
        while(temp!=NULL){
            res.push_back(temp->val);
            temp=temp->next;
        }
        int n = res.size();
        for(int i=0;i<n;i++){
            if(i+k<=n){
                reverse(res.begin()+i,res.begin()+(i+k));
                i+=(k-1);
            }
        }
        ListNode* newlist = new ListNode(res[0]);
        ListNode* pointer = newlist;
        for(int i=1;i<n;i++){
            pointer->next=new ListNode(res[i]);
            pointer=pointer->next;
        }
       // for(auto&it:res)cout<<it<<" ";
       // cout<<endl;
        return newlist;
    }
};