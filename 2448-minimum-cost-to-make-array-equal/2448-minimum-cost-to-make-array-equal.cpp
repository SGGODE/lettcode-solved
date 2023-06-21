class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long start=*min_element(nums.begin(),nums.end());
        long long end=*max_element(nums.begin(),nums.end());
      //  long long res=INT_MAX;
        int index=0;
        while(start<=end){
            long long mid=(start+end)/2;
            long long tax=0;
            long long tax2=0;
            for(int i=0;i<nums.size();i++){
                tax=(long long)tax+(long long)abs(mid-nums[i])*cost[i];
            }
         //   ++mid;
            int temp=mid+1;
            for(int i=0;i<nums.size();i++){
                tax2=(long long)tax2+(long long)abs(temp-nums[i])*cost[i];
            }
           // --mid;
            if(tax<tax2){
              //  res=tax;
                index=mid;
                end=mid-1;
            }else{
               // res=min(res,tax);
                //index=mid+1;
                start=mid+1;
            }
            // res=min(res,min(tax2,tax));
            //cout<<start<<" "<<end<<" "<<res<<endl;
        }
        // return res;
       // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     long long sum=0;
        //     for(int j=0;j<nums.size();j++){
        //        // if(i==j)continue;
        //         sum=(long long)sum+(long long)abs(nums[j]-nums[i])*cost[j];
        //     }
        //     res=min(res,sum);
        // }
        long long res=0;
         for(int i=0;i<nums.size();i++){
                res=(long long)res+(long long)abs(index-nums[i])*cost[i];
          }
        return res;
    }
};