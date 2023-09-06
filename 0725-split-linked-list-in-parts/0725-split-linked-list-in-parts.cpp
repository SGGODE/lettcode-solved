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
private:
    vector<int> makevectro(int num,int k){
    int quotient = num / k;
    int remainder = num % k;
     vector<int>parts(k);
     for (int i = 0; i < k ; i++) {
        parts[i] = quotient;
      }
        int index=0;
    while(remainder!=0){
        if(index==k)index=0;
        parts[index]+=1;
        --remainder;
        ++index;
    }
        return parts;
    }
    int listsize(ListNode* head){
        int cnt=0;
        while(head!=NULL){
            ++cnt;
            head=head->next;
        }
        return cnt;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = listsize(head);
        vector<ListNode*>res(k);
        if(k>=len){
            int index=0;
            ListNode* curr = head;
            while(curr!=NULL){
                ListNode* next = curr->next;
                ListNode* temp = curr;
                temp->next=NULL;
                res[index]=temp;
                curr=next;
                ++index;
            }
        }else{
            vector<int>result = makevectro(len,k);
            int index=0;
            ListNode* curr=head;
            while(curr!=NULL){
                ListNode* temp = curr;
                result[index]-=1;
                ListNode* store=temp;
                while(temp!=NULL&&result[index]!=0){
                    temp=temp->next;
                    --result[index];
                }
                curr=temp->next;
                temp->next=NULL;
                res[index]=store;
                //head=head->next;
                ++index;
            }
        }
        return res;
    }
};