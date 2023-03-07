class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // vector<int>v(time);
         int n=time.size();
        if(totalTrips==1){
            return *min_element(time.begin(),time.end());
        }
        // int cnt=1;int trip=0;
        // while(trip!=totalTrips){
        //     for(auto it:time){
        //         if(cnt==1||it==1){
        //            if(it==1)++trip;
        //            // ++trip;
        //             continue;
        //         }
        //         if(it%cnt==0)++trip;
        //         // cout<<it<<endl;
        //         // cout<<cnt<<endl;
        //         // cout<<trip<<endl;
        //     }
        //     if(trip!=totalTrips)++cnt;
        // }
       // return cnt;
      long long int s=*min_element(time.begin(),time.end());
       long long int e=100000000000000;
        while(s<e){
          long long int m=(s+e)/2;
          long long int total=0;
            for(auto it:time){
                if(it==1)total+=m;
                else{
                   if(m>it){
                       total+=floor(m/it);
                       continue;
                   }
                   if(it%m==0)total+=(m/it); 
                   else{
                      // if(m>it)total+=floor(m/it);
                        total+=floor(m/it);
                   }
                }
            }
            if(totalTrips>total){
                s=m+1;
            }else{
                e=m;
            }
        }
        return s;
    }
};