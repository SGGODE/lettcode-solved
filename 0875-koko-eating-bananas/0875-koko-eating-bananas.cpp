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
         int s=1;
        int e=1000000000;
        while(s<e){
            int mid=(s+e)/2;
            int total=0;
            for(auto it:piles){
                total+=(it+mid-1)/mid;
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