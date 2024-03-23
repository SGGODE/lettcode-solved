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
    void reorderList(ListNode* head) {
        vector<int>list;
        ListNode* t = head;
        while(t!=NULL){
            list.push_back(t->val);
            t=t->next;
        }
        int n = list.size();
        vector<int>reorder;
        int i = 0,j = n-1;
        while(i<j){
            reorder.push_back(list[i]);
            reorder.push_back(list[j]);
            i++;
            j--;
        }
        if(i==j)reorder.push_back(list[i]);
        
        ListNode* result = head;
        for(int i=0;i<reorder.size();i++){
            result->val = reorder[i];
            result = result->next;
        }
    }
};