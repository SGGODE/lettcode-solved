//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

int floor(Node *root, int x);

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << floor(root, s) << "\n";
    }
}

// } Driver Code Ends


// Function to search a node in BST.
void find(Node* root,vector<int>&v){
    if(root==NULL)return;
    // if(root->data >= val){
    //     cnt=min(cnt,root->data);
    // }
    // if(root->data > val){
    //     find(root->left,val);
    // }
    // if(root->data < val){
    //     find(root->right,val);
    // }
    find(root->left,v);
    v.push_back(root->data);
    find(root->right,v);
}
int floor(Node* root, int x) {
    // Code here
     if (root == NULL) return -1;
    vector<int>v;
    find(root,v);
    int cnt=INT_MIN;
    sort(v.begin(),v.end());
    int n=v.size();
    for(int i=0;i<n;i++){
        if(v[i]<=x){
            cnt=max(cnt,v[i]);
        }
    }
    if(cnt==INT_MIN)return -1;
    return cnt;
}
