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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     //    unsigned int num1=0,num2=0;
     //    while(l1->next!=NULL){
     //        //cout<<(l1->val-'0')<<endl;
     //        //num1.push_back(l1->val);
     //        num1+=l1->val;
     //        num1*=10;
     //        l1=l1->next;
     //    }
     //    num1+=l1->val;
     //   // cout<<num1<<endl;
     //    while(l2->next!=NULL){
     //      num2+=l2->val;
     //        num2*=10;
     //        l2=l2->next;
     //    }
     //   // cout<<num2<<endl;
     //    num2+=l2->val;
     // //  cout<<(num1)<<endl;
     //    string x1=to_string(num1);
     //    string x2=to_string(num2);
     //    reverse(x1.begin(),x1.end());
     //    reverse(x2.begin(),x2.end());
     //    num1=0;num2=0;
     //    num1=stoll(x1);
     //    num2=stoll(x2);
     //    unsigned int num3=num1+num2;
     //    string x;
     //    x=to_string(num3);
     //    cout<<num1<<" "<<num2<<" "<<num3<<endl;
     //     // cout<<num3<<" "<<x<<endl;
     //    ListNode* temp=new ListNode(-1);
     //    ListNode* result=temp;
     //    // for(int i=0;i<x.size();i++){
     //    //   temp->next=new ListNode((x[i]));
     //    //     temp=temp->next;
     //    // }
     //    if(num3==0){
     //        temp->next=new ListNode(0);
     //        temp=temp->next;
     //    }
     //    while(num3!=0){
     //        int last=num3%10;
     //        temp->next=new ListNode(last);
     //        temp=temp->next;
     //        num3=num3/10;
     //    }
     //    return result->next;
          int carry = 0;
        ListNode* temp1=new ListNode(0);
        ListNode* temp=temp1;
       while(l1!=NULL||l2!=NULL||carry!=0){
           int val1=0;
           if(l1!=NULL){
               val1=l1->val;
               l1=l1->next;
           }
           int val2=0;
           if(l2!=NULL){
               val2=l2->val;
               l2=l2->next;
           }
           int sum=0;
           sum=val1+val2+carry;
           int digit=sum%10;
           temp->next=new ListNode(digit);
           temp=temp->next;
           carry=sum/10;
       }
        return temp1->next;
    }
};