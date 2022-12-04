class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
      // long long int sum=accumulate(nums.begin(), nums.end(), 0);
      //  // return sum;
      //   long long int dumsum=0;
      //   long long int n=nums.size();long long int j=0;long long int m=INT_MAX;
      //   if(n==1)return 0;
      //   int cnt=n-1;int cnt2=1;
      //  for(int i=0;i<n;i++){
      //      dumsum+=nums[i];long long int x=0,y=0;
      //      sum-=nums[i];
      //     // if(i==n-1)continue;
      //      if(cnt==0){
      //        y=dumsum/cnt2;
      //        if(abs(y-x)<m){
      //          j=i;
      //          m=abs(y-x);
      //      }
      //          continue;
      //      }//return j;
      //       x=sum/cnt;
      //      //cout<<cnt<<endl;
      //       y=dumsum/cnt2;
      //      if(abs(y-x)<m){
      //          j=i;
      //          m=abs(y-x);
      //      }
      //      cnt--;
      //      cnt2++;
      //  }
      //   return j;
        int n=nums.size();
        //vector<int>prefix(n,-1);
        long long int sum=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
          //  prefix[i]=sum;
        }
        long long int minindex=-1,minvalue=INT_MAX, currsum=0;
        for(int i=0;i<n;i++){
          //  int val=prefix[n-1]-prefix[i];
            currsum+=nums[i];
            sum-=nums[i];
            int  val= i==n-1 ? 0:sum/(n-1-i);
            if(abs(val-(currsum/(i+1)))<minvalue){
                minindex=i;
                minvalue=(abs(val-currsum/(i+1)));
            }
        }
                          return minindex;
    }
};