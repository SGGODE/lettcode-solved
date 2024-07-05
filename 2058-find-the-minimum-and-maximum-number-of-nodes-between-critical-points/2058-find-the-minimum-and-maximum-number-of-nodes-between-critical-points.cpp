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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>index;
        int ind = 0;
        ListNode* thead = head;
        while(thead->next!=NULL&&thead->next->next!=NULL){
              if(thead->val < thead->next->val && thead->next->next->val < thead->next->val){
                  index.push_back(ind);
                  ++ind;
              }else if(thead->val > thead->next->val && thead->next->next->val > thead->next->val){
                  index.push_back(ind);
                  ++ind;
              }else{
                  ++ind;
              } 
            thead = thead->next;
        }
        if(index.size() < 2)return {-1,-1};
        int n = index.size();
        int mind = 1e9;
        int mxd = 0;
        for(int i = 1; i < n ; i++){
            mind = min(mind , index[i]-index[i-1]);
        }
        return {mind,index[n-1]-index[0]};
    }
};