class Solution {
private:
    int dp[11][2][2][2][10];
    int sub(string&nums,map<int,int>&mp,int index,int start,int tight,bool rep){
        if(index==nums.size()){
            if(rep)return 1;
            return 0;
        }
        if(dp[index][start][tight][rep][mp.size()]!=-1)return dp[index][start][tight][rep][mp.size()];
        int high = 9;
        if(tight)high = nums[index]-'0';
        int ans = 0;
        for(int i=0;i<=high;i++){
            if(start){
                if(mp.count(i)){
                    ans+=sub(nums,mp,index+1,start,tight&(i==high),1);
                }else{
                    mp[i]++;
                    ans+=sub(nums,mp,index+1,start,tight&(i==high),rep);
                    mp.erase(i);
                }
            }else{
                if(i!=0){
                    mp[i]++;
                    ans+=sub(nums,mp,index+1,1,tight&(i==high),rep);
                    mp.erase(i);
                }else{
                    ans+=sub(nums,mp,index+1,0,tight&(i==high),rep);
                }
            }
        }
        return dp[index][start][tight][rep][mp.size()]=ans;
    }
public:
    int numDupDigitsAtMostN(int n) {
        string temp = to_string(n);
        map<int,int>mp;
        memset(dp,-1,sizeof(dp));
        return sub(temp,mp,0,0,1,0);
    }
};