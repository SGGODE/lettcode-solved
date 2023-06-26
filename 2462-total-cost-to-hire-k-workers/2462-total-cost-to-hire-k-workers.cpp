class Solution {
public:
    long long totalCost(vector<int>&nums, int k, int can) {
        int n =nums.size();
        vector<bool>vis(n,0);
        long long int sum=0;
        priority_queue<int,vector<int>,greater<int>>start;
         priority_queue<int,vector<int>,greater<int>>end;
        int temp=can;
        int startend=0;
        for(int i=0;i<n&&temp>0;i++){
            --temp;
             start.push(nums[i]);
             vis[i]=1;
            if(temp==0||i==n-1)startend=i;
        }
        int endend=0;
        temp=can;
        for(int i=n-1;i>=0&&temp>0&&i>startend;i--){
          if(temp>0&&i>startend){
               --temp;
               end.push(nums[i]);
               vis[i]=1;
          }
           //}else{
              //  endend=i-1;
              //  break;
           //}
          if(temp==0||i==startend)endend=i;
        }
        while(k--){
           int firstclass=1e9;
           int secondclass=1e9;
            if(!start.empty())firstclass=start.top();
           if(!end.empty())secondclass=end.top();
           if(firstclass<=secondclass){
               sum=(long long)sum+firstclass;
               start.pop();
               if((startend+1)<endend){
                   ++startend;
                   while(startend<endend&&start.size()<can){
                       start.push(nums[startend]);
                       ++startend;
                   }
                   if(endend==startend)1;
                   else --startend;
               }
           }else{
               sum=(long long)sum+secondclass;
               end.pop();
               //cout<<endend<<" "<<startend<<endl;
               if((endend-1)>startend){
                   --endend;
                   while(endend>startend&&end.size()<can){
                       end.push(nums[endend]);
                       --endend;
                   }
                   if(endend==startend)1;
                   else ++endend;
               }
           }
        }
        return sum;
    }
};