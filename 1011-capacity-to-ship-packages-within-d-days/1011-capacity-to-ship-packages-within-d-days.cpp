class Solution {
private:
  bool check(vector<int>&v,int index,int sum,int remain,int n){
       int xsum=0;
       int cnt=0;
       for(int i=index;i<n;i++){
           xsum+=v[i];
           if(xsum>=sum){
               if(xsum==sum)xsum=0;
               else xsum=v[i];
               ++cnt;
           }
            if(n-i==remain-cnt)return 1;
       }
       if(xsum!=0)++cnt;
       return cnt==remain;
}

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int m=*max_element(weights.begin(),weights.end());
      //  int x=days;
        if(days==1){
            int sum=0;
            for(auto it:weights)sum+=it;
            return sum;
        }
        int part=1;int n=weights.size();int i=0;
        while(1){
                if(check(weights,i,m,days,n)){
                    return m;
                }
            ++m;
        }
        return m;
    }
};