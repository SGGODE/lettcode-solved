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
    ListNode* removeNodes(ListNode* head) {
        vector<int>res;
        while(head!=NULL){
            res.push_back(head->val);
            head=head->next;
        }
        vector<int>finalx;
        int num = res[res.size()-1];
        for(int i=res.size()-1;i>=0;i--){
            if(res[i]>=num)finalx.push_back(res[i]);
            num = max(num,res[i]);
        }
        reverse(finalx.begin(),finalx.end());
        if(!finalx.empty())head = new ListNode(finalx[0]);
        ListNode* temp = head;
        for(int i=1;i<finalx.size();i++){
            temp->next = new ListNode(finalx[i]);
            temp = temp->next;
        }
        return head;
    }
};