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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* headx=head;
        vector<int>res;
        while(headx!=NULL){
            res.push_back(headx->val);
            headx=headx->next;
        }
        while(1){
            vector<int>result;
            vector<bool>vis(res.size(),0);bool flag = 1;
            for(int i=0;i<res.size();i++){
                int sum = 0;
                for(int j=i;j<res.size();j++){
                    sum+=res[j];
                    if(sum==0){
                        flag=0;
                        for(int k=i;k<j+1;k++)vis[k]=1;
                        i=j;
                        break;
                    }
                }
            }
            for(int i=0;i<res.size();i++){
                if(!vis[i])result.push_back(res[i]);
            }
            if(flag)break;
            res=result;
        }
        if(res.empty())return NULL;
        ListNode* xhead = new ListNode(res[0]);
        ListNode* nextx = xhead;
        for(int i=1;i<res.size();i++){
            nextx->next = new ListNode(res[i]);
            nextx=nextx->next;
        }
        return xhead;
    }
};