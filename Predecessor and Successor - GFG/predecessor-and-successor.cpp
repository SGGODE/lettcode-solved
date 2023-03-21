//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}
// } Driver Code Ends

#include<bits/stdc++.h>
/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
// int v[101]={0};
// int i=0;
void inorder(Node*& root,vector<int>&v){
    if(root==NULL)return;
    inorder(root->left,v);
    v.push_back(root->key);
   // ++i;
    inorder(root->right,v);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){

// Your code goes here
   //int j=0;
  // int v[101];
   vector<int>v;
   inorder(root,v);
   int n=v.size();
   int cntmin=1000;
   int cntmax=-1000;
  // sort(v.begin(),v.end());
   for(int j=0;j<n;j++){
       if(v[j]==key)continue;
       if(v[j]<key){
          cntmax=v[j]; 
       }else{
           cntmin=v[j];break;
       }
   }
   if(cntmin==1000){
       cntmin=-1;
   }
   if(cntmax==-1000){
       cntmax=-1;
   }
   pre=new Node(cntmax);
   suc=new Node(cntmin);
}