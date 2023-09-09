#define ll long long
class Solution {
public:
    ll dp[11][2][2][10][10][20];
    // ll check(int low,int k){
    //     string s = to_string(low);
    //     int odd=0,even=0;
    //     for(int i=0;i<s.size();i++){
    //         int num = s[i]-'0';
    //         if(num%2)++odd;
    //         else ++even;
    //     }
    //     return (low%k==0)&&(odd==even);
    // }
    int sub(string&x,int sum,int index,int tight,int even,int odd,int leading,int k){
        if(index==x.size()){
           if(sum==0&&odd==even)return 1;
            return 0;
        }
        if(dp[index][tight][leading][even][odd][sum]!=-1)return dp[index][tight][leading][even][odd][sum];
        long long int res = 0;
        int range = tight?x[index]-'0':9;
        for(int i=0;i<=range;i++){
            if(leading){
                if(i==0)res = res+sub(x,(sum*10)+i,index+1,tight&(i==range),even,odd,leading,k);
                else{
                    if(i%2)res = res+sub(x,((sum*10)+i)%k,index+1,tight&(i==range),even,odd+1,0,k);
                    else res = res+sub(x,((sum*10)+i)%k,index+1,tight&(i==range),even+1,odd,0,k);
               }
            }else{
                if(i%2)res = res+sub(x,((sum*10)+i)%k,index+1,tight&(i==range),even,odd+1,leading,k);
                else res = res+sub(x,((sum*10)+i)%k,index+1,tight&(i==range),even+1,odd,leading,k);
             } 
        }
        return dp[index][tight][leading][even][odd][sum]=res;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string x = to_string(low-1);
        //string m = "";
        memset(dp,-1,sizeof(dp));
        int a = sub(x,0,0,1,0,0,1,k);
        string s = to_string(high);
        memset(dp,-1,sizeof(dp));
        int b = sub(s,0,0,1,0,0,1,k);
        //int cnt = check(low,k);
        return (b-a);
    }
};