class Solution {
private:
    bool sub(vector<int>&dp,string&s,int turn,int aindex,int bindex){ 
     if(s.size()<=2&&!turn)return 1;
     if(s.size()<=2&&turn)return 0;
     if(dp[turn]!=-1)return dp[turn];
      bool ans=0;
      if(turn){
          bool flag=1;
         for(int i=aindex;i<s.size()-1;i++){
             if(s[i]=='A'&&s[i-1]=='A'&&s[i+1]=='A'){
                 //string temp=s;
                 s.erase(i,1);
                 flag=0;
                 ans=max(ans,sub(dp,s,0,i,bindex));
             }
         }
          if(flag)return 0;
      }else{
           bool flag=1;
          for(int i=bindex;i<s.size()-1;i++){
             if(s[i]=='B'&&s[i-1]=='B'&&s[i+1]=='B'){
                // string temp=s;
                 s.erase(i,1);
                 flag=0;
                 ans=max(ans,sub(dp,s,1,aindex,i));
             }
         }
          if(flag)return 1;
      }
        return dp[turn]=ans;
    }
public:
    bool winnerOfGame(string nums) {
     //   vector<int>dp(2,-1);
      //  return sub(dp,colors,1,1,1);
       long long int count1=0,count2=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i-1]==nums[i]&&nums[i]==nums[i+1]){
                if(nums[i]=='B'){
                    int cnt=1;int j=i;
                    while(j<nums.size()&&nums[j]=='B'){++j;++cnt;}
                   // cout<<nums<<" "<<cnt<<" "<<1<<endl;
                    i=j-1;
                    count2=(long long )count2+(cnt-2);
                }else{
                   int cnt=1;int j=i;
                    while(j<nums.size()&&nums[j]=='A'){++j;++cnt;}
                    count1=(long long)count1+(cnt-2); 
                    i=j-1;
                   // cout<<nums<<" "<<cnt<<" "<<2<<endl;
                }
            }
        }
        return count1>count2;
    }
};