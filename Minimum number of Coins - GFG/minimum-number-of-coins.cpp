//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
        // code here
        vector<int>res;
        //vector<int>v{ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        while(n!=0){
            if(n<2){
              n=n-1;
              res.push_back(1);
              continue;
            }if(n<5){
               n=n-2;
                res.push_back(2);
                continue;
            }if(n<10){
               n=n-5;
               res.push_back(5);
               continue;
            }if(n<20){
               n=n-10;
                res.push_back(10);
                continue;
            }if(n<50){
               n=n-20;
                res.push_back(20);
                continue;
            }if(n<100){
               n=n-50;
                res.push_back(50);
                continue;
            }if(n<200){
               n=n-100;
                res.push_back(100);
                continue;
            }if(n<500){
               n=n-200;
                res.push_back(200);
                continue;
            }if(n<2000){
               n=n-500;
                res.push_back(500);
                continue;
            }if(n>2000){
                n=n-2000;
                res.push_back(2000);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends