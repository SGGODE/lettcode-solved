class Solution {
public:
    int bestClosingTime(string customers) {
         int index=0;int n=customers.size();
        // vector<int>v(n),x(n);
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //    if(customers[i]=='N')++cnt;
        //    v[i]=cnt;
        // }cnt=0;
        // for(int i=n-1;i>=0;i--){
        //    if(customers[i]=='Y')++cnt;
        //    x[i]=cnt;
        // }
        // for(int i=;i<n;i++){
        //     int temp=v[i-1]+x[i];
        //     if(temp<mincnt){
        //         index=i;
        //         mincnt=temp;
        //     }
        // }
        // return index;
        int cnt=0;int micnt=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y')cnt++;
        }
         int mincnt=cnt;
        for(int i=0;i<n;i++){
            cnt+= customers[i]=='Y' ? -1:1;
            if(cnt<mincnt){
                mincnt=cnt;
                index=i+1;
            }
        }
        return index;
    }
};