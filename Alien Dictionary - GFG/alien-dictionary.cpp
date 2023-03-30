//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int k) {
        //code here
        vector<int>adj[k];
        for(int i=0;i<N-1;i++){
            string a=dict[i+1];
            string x=dict[i];
            int m=min(a.size(),x.size());
           for(int j=0;j<m;j++){
               if(a[j]==x[j]){
                   continue;
               }else{
                  adj[x[j]-'a'].push_back(a[j]-'a');
                   break;
               }
           }
        }
        vector<int>indegree(k,0);
        for(int i=0;i<k;i++){
            for(auto it:adj[i]){
               // cout<<it<<" ";
                indegree[it]++;
            }
          //  cout<<endl;
        }
      //  cout<<")"<<endl;
        queue<int>pq;
        for(int i=0;i<k;i++){
            if(indegree[i]==0)pq.push(i);
           // cout<<indegree[i]<<endl;
        }
        vector<int>res;
        while(!pq.empty()){
            int temp=pq.front();
            //cout<<temp<<endl;
            pq.pop();
            res.push_back(temp);
            for(auto it:adj[temp]){
                --indegree[it];
                if(indegree[it]==0)pq.push(it);
            }
        }
        string s;
        for(auto it:res){
           s.push_back(it+'a');
          //  cout<<it<<endl;
        }
       // cout<<s<<endl;
        //reverse(s.begin(),s.end());
        return s;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends