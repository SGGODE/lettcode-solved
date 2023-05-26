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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int>arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        // int rowstart=0;
        // int colstart=0;
        // int rowend=m;
        // int colend=n;
        vector<vector<int>>mat(m,vector<int>(n,-1));
        int num=arr.size();
        // int index=0;
        // while(1){
        //     if(colend<colstart)break;
        //     for(int i=colstart;i<colend;i++){
        //         res[rowstart][i]=arr[index++];
        //     }
        //     ++rowstart;
        //     if(rowstart>rowend)break;
        //     for(int i=rowstart;i<rowend;i++){
        //         res[i][colend]=arr[index++];
        //     }
        //     --colend;
        //     if(colend<colstart)break;
        //     for(int i=colend;i>=colstart;i--){
        //         res[rowend][i]=arr[index++];
        //     }
        //     --rowend;
        //     if(rowstart>rowend)break;
        //     for(int i=rowend;i>=rowstart;i--){
        //         res[colstart][i]=arr[index++];
        //     }
        //     --colstart;
        // }
        // return res;
    int top = 0,bottom = m - 1,left = 0,right = n - 1;
    int index = 0;
    while (1) {
        if (left > right||index==num)
            break;
 
        // print top row
        for (int i = left; i <= right&&index<num; i++){
            mat[top][i] = arr[index++];
            
        }
        top++;
 
        if (top > bottom||index==num)
            break;
 
        // print right column
        for (int i = top; i <= bottom&&index<num; i++)
            mat[i][right] = arr[index++];
        right--;
 
        if (left > right||index==num)
            break;
 
        // print bottom row
        for (int i = right; i >= left&&index<num; i--)
            mat[bottom][i] = arr[index++];
        bottom--;
 
        if (top > bottom||index==num)
            break;
 
        // print left column
        for (int i = bottom; i >= top&&index<num; i--)
            mat[i][left] = arr[index++];
        left++;
    }
        return mat;
    }
};