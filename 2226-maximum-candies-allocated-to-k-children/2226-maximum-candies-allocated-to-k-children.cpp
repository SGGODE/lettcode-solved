class Solution {
#define ll long long
    bool check(vector<int>&candi,int sum,int k){
        for(int i=0;i<candi.size();i++){
            if(candi[i]>sum){
                k-=(int)(candi[i]/sum);
            }
        }
        //if(k<=0)
        return k<=0;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
       // int sum=;
       // ll sum= accumulate(candies.begin(),candies.end(),0);
       //  if(sum<k)return 0;
       //  map<ll,ll>mp;
       //  for(auto it:candies)mp[it]++;
         ll m=*max_element(candies.begin(),candies.end());
       // // mp[m]--;
       //  ll average=sum/k;
       //  // ll cnt=k;
       //  // cnt-=(m/average);
       //  if(k<=mp[m])return m;
       //  bool flag=0; mp[m]--;
       //  while(!flag){
       //      ll max_satis=m/average;
       //      ll consi=k-max_satis;
       //      for(auto it:mp){
       //          if(it.first>average){
       //              ll ma_satis=it.first/average;
       //              consi-=ma_satis;
       //          }
       //          if(consi<=0)return average;
       //      }
       //      average--;
       //  }
       //  return 0;
        //int res=INT_MIN;
        int s=0,e=10000000;
        while(s<e){
           long long int mid=(s+e+1)/2;
          long long int cnt=0;
            for(int i=0;i<candies.size()&&cnt<=k;i++){
                cnt+=candies[i]/mid;
            }
            if(cnt>=k){
                s=mid;
            }else {
                e=mid-1;
            }
        }
       // if(res==INT_MIN)return 0;
        return s;
    }
};