//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int k, vector<int> &hand) {
        // code here
        if(n%k!=0)return 0;
        map<long long int,long long int>mp;
        for(auto it:hand)mp[it]++;
        set<long long int>s(hand.begin(),hand.end());
       // for(auto it:s)cout<<it<<" ";
        //cout<<endl;
        int round=n/k;
        while(round!=0){
            --round;
            int curr=0;bool flag=0;
            for(auto it:s){
                curr=it;
                 --mp[it];
                //cout<<mp[it]<<endl;
                  if(mp[it]==0){
                    //  cout<<"yes"<<endl;
                       flag=1;
                       mp.erase(it);
                       s.erase(it);
                   }
                break;
            }
            int cnt=1;
            for(auto it:s){
               // cout<<it<<" "<<curr<<endl;
                if(cnt==1&&!flag){
                    flag=1;
                    continue;
                }
              //   cout<<it<<" "<<curr<<endl;
                if(it==(curr+1)&&cnt<k){
                    ++cnt;
                    --mp[it];
                    curr=it;
                   if(mp[it]==0){
                       mp.erase(it);
                       s.erase(it);
                   }
                }else break;
            }
            if(cnt<k){
                 //cout<<cnt<<" "<<curr<<" "<<round<<endl;
                //cout<<nums[i]<<endl;return 0;
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends