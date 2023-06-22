//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Node{
    public:
    Node* links[26];
    int newcalls=0;
    bool flag=0;
    bool contain(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
        ++newcalls;
    }
    int newNodes(){
        return newcalls;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setend(){
        flag=1;
    }
};

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N){
        // your code here
        Node* root=new Node();
        string large;
        int maxsize=INT_MAX;
        sort(arr,arr+N);
        reverse(arr,arr+N);
        for(int i=0;i<N;i++){
            Node* node=root;
            if(arr[i].size()<maxsize){
                large=arr[i];
                maxsize=arr[i].size();
            }
            for(int j=0;j<arr[i].size();j++){
                if(!node->contain(arr[i][j])){
                    node->put(arr[i][j],new Node());
                }
                node=node->get(arr[i][j]);
            }
            node->setend();
        }
        if((root->newNodes())>1)return "-1";
        Node* node=root;
        for(int i=0;i<large.size();i++){
            if(node->newNodes()>1){
                return large.substr(0,i);
            }
            node=node->get(large[i]);
        }
        return large;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends