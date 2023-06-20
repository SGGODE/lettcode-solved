class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        long long int sum=0;
        vector<long long int>prefix(n,0);
        for(int i=0;i<n;i++){
            sum=(long long)sum+nums[i];
            prefix[i]=sum;
        }
        // for(auto &it:prefix)cout<<it<<" ";
        // cout<<endl;
        vector<int>res(n,-1);
        if(k<n){
            //cout<<(n-k)+1<<endl;
        for(int i=k;i<(n-k);i++){
           // cout<<i<<endl;
            long long int curr=prefix[(i+k)];
            if(((i-k)-1)>=0){
                curr=(long long)curr-prefix[(i-k)-1];
                //cout<<i<<" "<<prefix[(i-k)-1]<<endl;
            }
            res[i]=floor(curr/((2*k)+1));
           // cout<<res[i]<<" "<<prefix[i+k]<<" "<<endl;
          }
        }
        return res;
    }
};