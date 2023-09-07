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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>res;
        ListNode* temp = head;
        while(temp!=NULL){
            res.push_back(temp->val);
            temp=temp->next;
        }
        reverse(res.begin()+(left-1),res.begin()+right);
       // for(auto&it:res)cout<<it<<" ";
       // cout<<endl;
        ListNode* newList = new ListNode(res[0]); 
        temp = newList;
        for(int i=1;i<res.size();i++){
            temp->next = new ListNode(res[i]);
            temp = temp->next;
        }
        return newList;
    }
};