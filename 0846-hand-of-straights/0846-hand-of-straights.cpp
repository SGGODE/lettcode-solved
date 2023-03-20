class Solution {
public:
    bool isNStraightHand(vector<int>&hand, int k) {
        int n=hand.size();
      //   if(n%k!=0){
      //     //  cout<<'y'<<k<<endl;
      //       return 0;
      //   }
      //  // map<pair<int,int>>mp;
      //  // for(auto it:nums)mp[it]++;
      //   vector<bool>vis(n,0);
      //   sort(nums.begin(),nums.end());
      // for(int i=0;i<n;i++){
      //  long long int curr=nums[i];long long int cnt=1;
      //    if(!vis[i]){
      //       for(int j=i+1;j<n;j++){
      //           if((curr+1)==nums[j]&&cnt<k&&!vis[j]){
      //               vis[j]=1;
      //               curr=nums[j];
      //               ++cnt;
      //           }
      //       }
      //       if(cnt<k){
      //           cout<<cnt<<" "<<curr<<" "<<nums[i]<<endl;
      //           cout<<nums[i]<<endl;return 0;
      //       }
      //    }
      //  }
      //   return 1;
        if(n%k!=0)return 0;
        map<long long int,long long int>mp;
        for(auto it:hand)mp[it]++;
        set<long long int>s(hand.begin(),hand.end());
        for(auto it:s)cout<<it<<" ";
        cout<<endl;
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
                cout<<it<<" "<<curr<<endl;
                if(cnt==1&&!flag){
                    flag=1;
                    continue;
                }
                 cout<<it<<" "<<curr<<endl;
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
                 cout<<cnt<<" "<<curr<<" "<<round<<endl;
                //cout<<nums[i]<<endl;return 0;
                return 0;
            }
        }
        return 1;
    }
};