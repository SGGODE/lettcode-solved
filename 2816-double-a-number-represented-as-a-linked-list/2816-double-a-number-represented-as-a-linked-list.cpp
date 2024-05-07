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
    ListNode* doubleIt(ListNode* head) {
        vector<int>temp;
        while(head!=NULL){
            temp.push_back(head->val);
            head=head->next;
        }
        reverse(temp.begin(),temp.end());
        vector<int>result;
        int rem = 0;
        for(int i=0;i<temp.size();i++){
            rem += 2*temp[i];
            result.push_back(rem%10);
            rem=rem/10;
        }
        while(rem!=0){
            result.push_back(rem%10);
            rem/=10;
        }
        reverse(result.begin(),result.end());
        if(!result.empty())head = new ListNode(result[0]);
        ListNode* tempx = head;
        for(int i=1;i<result.size();i++){
            tempx->next = new ListNode(result[i]);
            tempx=tempx->next;
        }
       // for(auto&it:result)cout<<it<<" ";
        return head;
    }
};