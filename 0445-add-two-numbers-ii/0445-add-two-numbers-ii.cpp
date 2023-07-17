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
        vector<int>v1,v2;
        ListNode* temp1;
        ListNode* temp2;
        temp1=l1;
        temp2=l2;
        while(temp1!=NULL){
            v1.push_back(temp1->val);
            temp1=temp1->next;
        }
         while(temp2!=NULL){
            v2.push_back(temp2->val);
            temp2=temp2->next;
        }
       // for(auto&it:v1)cout<<it<<" ";cout<<endl;for(auto&it:v2)cout<<it<<" ";cout<<endl;
        int n = v1.size();
        int m = v2.size();
        int i=n-1;
        int j=m-1;
        int rem=0;
        vector<int>res;
        while(i>=0&&j>=0){
            int add = v1[i]+v2[j];
            add+=rem;
            int cnt=0;
             while((add-cnt)>=10){
                cnt+=10;
              }
            if(cnt%10==0){
                rem=cnt/10;
            }else rem=cnt;
            res.push_back(add-cnt);
            //cout<<add<<" "<<rem<<" "<<cnt<<endl;
            --i;--j;
        }
        while(i>=0){
            int add=v1[i];
            add+=rem;
            int cnt=0;
            while((add-cnt)>=10){
                cnt+=10;
             }
            if(cnt%10==0){
                rem=cnt/10;
            }else rem=cnt;
            res.push_back(add-cnt);
            --i;//--j;
        }
        while(j>=0){
            int add=v2[j];
            add+=rem;
            int cnt=0;
            while((add-cnt)>=10){
                cnt+=10;
             }
          if(cnt%10==0){
                rem=cnt/10;
            }else rem=cnt;
            res.push_back(add-cnt);
            --j;//--j;
        }
        if(rem!=0){
            res.push_back(rem);
        }
        reverse(res.begin(),res.end());
      //  for(auto&it:res)cout<<it<<" ";
       // cout<<endl;
      //  return l1;
        ListNode* head=new ListNode(res[0]);
        ListNode* temp=head;
        for(int i=1;i<res.size();i++){
            temp->next=new ListNode(res[i]);
            temp=temp->next;
        }
        return head;
    }
};