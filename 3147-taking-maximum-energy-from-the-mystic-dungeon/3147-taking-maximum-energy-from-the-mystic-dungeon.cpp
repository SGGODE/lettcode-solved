class Solution {
private:
    vector<int>dp;
    int sub(vector<int>&energy,int index,int k){
        if(index>=energy.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int ans = -1e9;
        ans = max(ans,energy[index]+sub(energy,index+k,k));
        return dp[index]=ans;
    }
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        dp.resize(n,-1);
        int answer = -1e9;
        for(int i=0;i<n;i++){
            answer = max(answer,sub(energy,i,k));
        }
        return answer;
    }
};