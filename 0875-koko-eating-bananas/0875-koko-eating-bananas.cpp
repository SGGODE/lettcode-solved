class Solution {
private:
    bool check(vector<int>&v,int sum,int h){
        int xsum=0;int cnt=0;
        for(int i=0;i<v.size();i++){
            xsum+=v[i];
            while(xsum>=sum){
             ++cnt;
             xsum-=sum;
            }
            if(xsum!=0)
            ++cnt;
            xsum=0;
        }
        //cout<<cnt<<endl;
        return cnt==h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       //  int n=piles.size();
       //  if(n==1)return piles[0];
       //  if(n==h){
       //      return *max_element(piles.begin(),piles.end());
       //  }
       //  int m=*min_element(piles.begin(),piles.end());
       //  while(1){
       //     if(check(piles,m,h)){
       //         return m;
       //     }
       //  ++m;
       // }
       // return m;
        int s=1;
        int e=1000000000;
        while(s<e){
          long long  int total=0;
            int mid=(s+e)/2;
            for(auto it:piles){
              long long int x=(it+mid-1)/mid;
                total+=x;
            }
            if(total>h){
                s=mid+1;
            }else{
                e=mid;
            }
        }
        return s;
    }
};