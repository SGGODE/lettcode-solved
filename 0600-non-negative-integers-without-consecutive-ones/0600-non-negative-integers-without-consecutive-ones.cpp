class Solution {
private:
    int dp[33][2][2][2];
    string DecimalToBinary(int num){
    string str;
      while(num){
      if(num & 1)
        str+='1';
      else 
        str+='0';
      num>>=1;
    }   
        reverse(str.begin(),str.end());
      return str;
}
    int sub(string&temp,int index,int tight,int prev,int flag){
        if(index==temp.size()){
            if(flag)return 0;
            return 1;
        }
        if(dp[index][tight][prev][flag]!=-1)return dp[index][tight][prev][flag];
        int limit = 1;
        if(tight)limit=temp[index]-'0';
        int ans=0;
        for(int i=0;i<=limit;i++){
            if(prev==1&&i==1){
                ans+=sub(temp,index+1,tight&(i==limit),1,1);
            }else{
               ans+=sub(temp,index+1,tight&(i==limit),i,flag);
            }
        }
        return dp[index][tight][prev][flag]=ans;
    }
public:
    int findIntegers(int n) {
        string temp = DecimalToBinary(n);
        //cout<<temp<<endl;
        memset(dp,-1,sizeof(dp));
        return sub(temp,0,1,0,0);
    }
};